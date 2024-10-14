#include "CardinalityMap.hpp"
#include "On_vHLL.hpp"
#include "xxhash32.h"
#include <catch2/catch.hpp>
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
#include <stdexcept>

#ifdef TEST_BINARY_INPUT_PATH
static std::string testBinaryInputPath = TEST_BINARY_INPUT_PATH;
#else
static std::string testBinaryInputPath = "test/";
#endif

/// @brief
/// 测试on_vhll算法，保存结果。true_card低于500的忽略,要求相对误差小于0.1。

namespace datasketches {

std::random_device rd;

// spdlog::level::level_enum log_level = spdlog::level::info;
const uint32_t STAGE_NUM = 4;
const uint32_t STAGE_ROW = 8192;
const uint32_t STAGE_COL = 8192;
const size_t REPEAT_TIME = 1;
const uint32_t MASTER_SEED = rd();
const int LOWER_BOUND_FILTER = 500;

TEST_CASE("on_vhll test", "on_vhll") {
  //数据路径
  std::string data_path = "../../../datasets/on_vhll/uniq/test.uniq";
  std::string groundtruth_path =
      "../../../datasets/on_vhll/groundtruth/test.groundtruth";

  //初始化
  uint32_t seed = 45;
  On_vHLL sketch(STAGE_NUM, STAGE_ROW, STAGE_COL, seed);
  std::string src_ip;
  std::string dst_ip;
  size_t round = 0;
  int true_card = 0;
  double est_card;
  double r_err;
  sketch.resetSketch();
  sketch.resetSeed(XXHash32::hash(&round, sizeof(round), seed ^ MASTER_SEED));

  // 文件流创建
  std::ifstream infs(data_path);
  std::ifstream true_infs(groundtruth_path);
  if (!infs.is_open()) {
    FAIL("open error:" + data_path); // file open error
  }
  if (!true_infs.is_open()) {
    FAIL("open error:" + groundtruth_path); // file open error
  }

  // 执行on_vhll算法
  while (infs.good()) {
    infs >> src_ip >> dst_ip;
    if (infs.eof())
      break;
    sketch.update(src_ip.c_str(), src_ip.length(), dst_ip.c_str(),
                  dst_ip.length());
  }

  auto now = std::chrono::system_clock::now();
  std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
  std::tm *local_time = std::localtime(&now_time_t);
  std::ostringstream result_filename;
  result_filename << "result_" << (local_time->tm_year + 1900) << "_"
                  << (local_time->tm_mon + 1) << "_" << local_time->tm_mday
                  << "_" << local_time->tm_hour << "_" << local_time->tm_min
                  << "_" << local_time->tm_sec << ".csv";
  std::ofstream result(result_filename.str()); // result文件
  result << "src_ip,est_card,true_card,r_err\n";

  while (true_infs.good()) {
    true_infs >> src_ip >> true_card;
    if (true_infs.eof())
      break;
    if (true_card < LOWER_BOUND_FILTER)
      continue;
    est_card = (int)sketch.get_estimate(src_ip.c_str(), src_ip.length());
    r_err = get_r_error((double)true_card, est_card);
    result << src_ip << "," << (int)est_card << "," << true_card << "," << r_err
           << "\n";
    INFO(src_ip << " => est_card:" << (int)est_card
                << " true_card:" << true_card << " r_err:" << r_err);
    REQUIRE(r_err < 0.1);
  }

  //关闭文件
  infs.close();
  true_infs.close();
  result.close();
}

} /* namespace datasketches */