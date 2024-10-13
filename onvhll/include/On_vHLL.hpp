#ifndef ON_VHLL_HPP
#define ON_VHLL_HPP

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <numeric>
#include <vector>

#include "AccessStatics.hpp"
#include "EMatrix.hpp"
#include "TwoTupleSketch.h"
#include "xxhash32.h"

namespace datasketches {

class On_vHLL : public TwoTupleSketch {
public:
  static const std::uint32_t HISTOGRAM_LEN = 32;

private:
  std::uint32_t stage_num;
  std::uint32_t row;
  std::uint32_t col;
  std::uint32_t master_seed;
  std::vector<std::shared_ptr<EMatrix>> stages;

public:
  Statistics op_statistics;

  On_vHLL(std::uint32_t stage_num, std::uint32_t row, std::uint32_t col, std::uint32_t master_seed)
      : op_statistics("../../result/operation_statistics/on_vhll_op_statistics.txt") {
    this->stage_num = stage_num;
    this->row = row;
    this->col = col;
    this->master_seed = master_seed;
    for (std::uint32_t s = 0; s < stage_num; ++s) {
      std::uint32_t stage_seed = XXHash32::hash(&master_seed, sizeof(master_seed), s);
      stages.push_back(std::make_shared<EMatrix>(row, col, stage_seed));
    }
  }

  bool update(const std::string &flow_id, const std::string &element_id) {
    bool FLAG_UPDATED = false;
    uint64_t flow_id_len = flow_id.length();
    uint64_t element_id_len = element_id.length();
    const char *ptr_flow_id = flow_id.c_str();
    const char *ptr_element_id = element_id.c_str();

    for (auto &stage : stages) {
      std::uint32_t select_row = stage->selectRowIdxByFlowID(ptr_flow_id, flow_id_len);
      std::uint32_t select_col = stage->selectColIdxByElementID(ptr_flow_id, flow_id_len, ptr_element_id, element_id_len);
      std::uint8_t leading_zeroes = stage->countLeaderZero(ptr_flow_id, flow_id_len, ptr_element_id, element_id_len);
      op_statistics.addHashCnt(3);
      std::uint8_t cur_val = stage->estimators[select_row][select_col];
      op_statistics.addMemoryAccess(1);
      cur_val = (cur_val >= HISTOGRAM_LEN) ? HISTOGRAM_LEN - 1 : cur_val;
      if (cur_val >= leading_zeroes) {
        continue;
      }
      FLAG_UPDATED = true;
      stage->estimators[select_row][select_col] = leading_zeroes;
      op_statistics.addMemoryAccess(1);
      stage->IUU.at(select_row)->update(cur_val, leading_zeroes);
      op_statistics.addMemoryAccess(2);
      stage->global_histogram.update(cur_val, leading_zeroes);
    }

    if (FLAG_UPDATED) {
      op_statistics.addSketchUpdateCnt(1);
    }

    return FLAG_UPDATED;
  }

  double get_estimate(const std::string &flow_id) {
    /* Using Global histogram to estimate n_hat */
    //        op_statistics.addSketchQueryCnt(1);
    //        std::vector<double> stage_res;
    //        std::vector<double> stage_total_spread;
    //        for (auto &stage : stages) {
    //            std::uint32_t select_row =
    //            stage->selectRowIdxByFlowID(ptr_flow_id, flow_id_len);
    //            op_statistics.addHashCnt(1);
    //
    //            stage_res.push_back(stage->IUU.at(select_row)->getEstimate());
    //            op_statistics.addMemoryAccess(1);
    //            stage_total_spread.push_back(stage->global_histogram.getEstimate());
    //        }
    //        double n_d_hat = getMedian(stage_res);
    //        double n_hat = getMedian(stage_total_spread);
    //        double factor = 1;
    //        if (row > 1)
    //            factor = (double)row / (row - 1);
    //        double n_f_hat = factor * (n_d_hat - n_hat / row);
    //        return n_f_hat;

    /* Using new algo and Global histogram to estimate n_hat */
    //        std::vector<double> stage_res;
    //        std::vector<double> stage_total_spread;
    //        for (auto &stage : stages) {
    //            std::uint32_t select_row =
    //            stage->selectRowIdxByFlowID(ptr_flow_id, flow_id_len);
    //            stage_res.push_back(stage->IUU.at(select_row)->getEstimate_new());
    //            stage_total_spread.push_back(stage->global_histogram.getEstimate_new());
    //        }
    //        double n_d_hat = getMedian(stage_res);
    //        double n_hat = getMedian(stage_total_spread);
    //        double factor = 1;
    //        if (row > 1)
    //            factor = (double)row / (row - 1);
    //        double n_f_hat = factor * (n_d_hat - n_hat / row);
    //        return n_f_hat;

    /* Using new algo and sum of IUUs to estimate n_hat */
    std::vector<double> stage_res;
    std::vector<double> stage_total_spread;
    for (auto &stage : stages) {
      double total_card = 0;
      const char *ptr_flow_id = flow_id.c_str();
      uint64_t flow_id_len = flow_id.length();
      std::uint32_t select_row = stage->selectRowIdxByFlowID(ptr_flow_id, flow_id_len);
      stage_res.push_back(stage->IUU.at(select_row)->getEstimate_new());

      for (std::uint32_t i = 0; i < stage->row; i++)
        total_card += stage->IUU.at(i)->getEstimate_new();
      stage_total_spread.push_back(total_card);
    }
    double n_d_hat = getAvg(stage_res);
    double n_hat = getAvg(stage_total_spread);
    double factor = 1;
    if (row > 1)
      factor = (double)row / (row - 1);
    double n_f_hat = factor * (n_d_hat - n_hat / row);
    return n_f_hat;

    /* Using sum of IUUs to estimate n_hat */
    //        std::vector<double> stage_res;
    //        std::vector<double> stage_total_spread;
    //        for (auto &stage : stages) {
    //            double total_card = 0;
    //            std::uint32_t select_row =
    //            stage->selectRowIdxByFlowID(ptr_flow_id, flow_id_len);
    //            stage_res.push_back(stage->IUU.at(select_row)->getEstimate());
    //
    //            for(std::uint32_t i = 0; i < stage->row; i++)
    //                total_card += stage->IUU.at(i)->getEstimate();
    //            stage_total_spread.push_back(total_card);
    //        }
    //        double n_d_hat = getAvg(stage_res);
    //        double n_hat = getAvg(stage_total_spread);
    //        double factor = 1;
    //        if (row > 1)
    //            factor = (double)row / (row - 1);
    //        double n_f_hat = factor * (n_d_hat - n_hat / row);
    //        return n_f_hat;
  }

  void flowTrace(const std::string &ptr_flow_id, const std::string &ptr_element_id) {
    bool FLAG = false;
    FLAG = update(ptr_flow_id, ptr_element_id);
    if (FLAG) {
      get_estimate(ptr_flow_id);
    }
  }

  void getHistogram(int true_card) {
    std::vector<double> stage_total_spread_1;
    std::vector<double> stage_total_spread_2;
    for (auto &stage : stages) {
      double total_card = 0;
      for (std::uint32_t i = 0; i < stage->row; i++) {
        total_card += stage->IUU.at(i)->getEstimate();
        //                spdlog::info("{}",
        //                stage->IUU.at(i)->printHistogram());
      }
      stage_total_spread_1.push_back(total_card);
      stage_total_spread_2.push_back(stage->global_histogram.getEstimate());
      //            spdlog::info("{}",
      //            stage->global_histogram.printHistogram());
      //            spdlog::info("sum:{}, glob:{}", total_card,
      //            stage->global_histogram.getEstimate_new());
    }
    double n_hat_1 = getAvg(stage_total_spread_1);
    double n_hat_2 = getAvg(stage_total_spread_2);
    std::cout << "sum:" << n_hat_1 << ",dev:" << n_hat_1 - true_card << ",r_dev:" << (n_hat_1 - true_card) / true_card;
    std::cout << "sum:" << n_hat_2 << ",dev:" << n_hat_2 - true_card << ",r_dev:" << (n_hat_2 - true_card) / true_card;
    // spdlog::info("sum:{}, dev:{}, r_dev:{}", n_hat_1, n_hat_1 - true_card,
    // (n_hat_1 - true_card) / true_card); spdlog::info("global_histogram:{},
    // dev:{}, r_dev:{}", n_hat_2, n_hat_2 - true_card, (n_hat_2 - true_card) /
    // true_card);
  }

  inline double getMedian(std::vector<double> &v) {
    std::uint32_t len = v.size();
    if (len == 0) {
      return 0;
    }
    std::sort(v.begin(), v.end());
    double ret = 0;
    if (len % 2 == 0) {
      ret = 0.5 * v.at(len / 2) + 0.5 * v.at(len / 2 - 1);
    } else {
      ret = v.at(len / 2);
    }
    return ret;
  }

  inline double getAvg(std::vector<double> &v) {
    std::uint32_t len = v.size();
    if (len == 0) {
      return 0;
    }
    double sum = accumulate(begin(v), end(v), 0.0);
    double avg = sum / v.size();

    return avg;
  }

  void saveStatistic() { op_statistics.save_to_file(); }

  void resetSketch() {
    for (auto s : stages) {
      s->reset();
    }
    op_statistics.reset();
  }

  void resetSeed(uint32_t new_seed) {
    this->master_seed = new_seed;
    for (std::uint32_t s = 0; s < stage_num; ++s) {
      std::uint32_t stage_seed = XXHash32::hash(&master_seed, sizeof(master_seed), s);
      stages.at(s)->resetSeed(stage_seed);
    }
  }
};

} // namespace datasketches

#endif