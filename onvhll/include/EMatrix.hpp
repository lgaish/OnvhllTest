#ifndef EMATRIX_HPP
#define EMATRIX_HPP

#include "leader_zero.h"
#include "xxhash32.h"
#include "MurmurHash3.h"
#include "Histogram.hpp"
#include "TwoTupleSketch.h"
#include <cstdint>
#include <cstdlib>
#include <iostream>
// #include <string>
#include <memory>
#include <vector>

namespace datasketches {

class EMatrix {
public:
    static std::uint32_t FLOW_HASH_SALT;
    static std::uint32_t ELEMENT_HASH_SALT;
    static std::uint32_t VALUE_HASH_SALT;

    std::uint32_t flow_hash_seed;
    std::uint32_t element_hash_seed;
    std::uint32_t value_hash_seed;

    std::uint32_t col;
    std::uint32_t row;

    std::uint8_t **estimators;
    std::vector<std::shared_ptr<Histogram>> IUU;
    Histogram global_histogram;

    EMatrix(std::uint32_t row, std::uint32_t col, std::uint32_t seed)
        : global_histogram(row * col) {
        this->row = row;
        this->col = col;
        this->flow_hash_seed = seed ^ FLOW_HASH_SALT;
        this->element_hash_seed = seed ^ ELEMENT_HASH_SALT;
        this->value_hash_seed = seed ^ VALUE_HASH_SALT;

        estimators = new std::uint8_t *[row];
        for (std::uint32_t i = 0; i < row; i++) {
            estimators[i] = new  std::uint8_t[col]();
        }

        for (std::uint32_t i = 0; i < row; i++) {
            IUU.push_back(std::make_shared<Histogram>(col));
        }
    }

    ~EMatrix() {
        for (std::uint32_t i = 0; i < row; i++) {
            delete[] estimators[i];
        }
        delete[] estimators;
    }
    void reset() {
        for (std::uint32_t i = 0; i < row; i++) {
            for (std::uint32_t j = 0; j < col; j++) {
                estimators[i][j] = 0;
            }
        }
        for (auto h : IUU) {
            h->reset();
        }
        global_histogram.reset();
    }

    void resetSeed(uint32_t seed) {
        this->flow_hash_seed = seed ^ FLOW_HASH_SALT;
        this->element_hash_seed = seed ^ ELEMENT_HASH_SALT;
        this->value_hash_seed = seed ^ VALUE_HASH_SALT;
    }

    std::uint32_t selectRowIdxByFlowID(const void *ptr_flow_id, std::uint64_t flow_id_len) {
        return XXHash32::hash(ptr_flow_id, flow_id_len, flow_hash_seed) % row;
    }

    std::uint32_t selectColIdxByElementID(const void *ptr_flow_id, std::uint64_t flow_id_len, const void *ptr_element_id, std::uint64_t element_id_len) {
        XXHash32 value_hash_fun(element_hash_seed);
        value_hash_fun.add(ptr_element_id, element_id_len);
        value_hash_fun.add(ptr_flow_id, flow_id_len);
        std::uint32_t hash_value = value_hash_fun.hash();
        return hash_value % col;
    }

    std::uint8_t countLeaderZero(const void *ptr_flow_id, std::uint64_t flow_id_len, const void *ptr_element_id, std::uint64_t element_id_len) {
        XXHash32 value_hash_fun(value_hash_seed);
        value_hash_fun.add(ptr_element_id, element_id_len);
        value_hash_fun.add(ptr_flow_id, flow_id_len);
        std::uint8_t hash_value = get_leader_zero(value_hash_fun.hash());
        return hash_value;
    }

    /* Functions designed for debugging */
    std::string getEstimatorInfo(std::uint32_t selected_row) {
        std::string debugStr;
        for (std::uint32_t i = 0; i < col; ++i) {
            uint32_t val = estimators[selected_row][i];
            // debugStr += fmt::format("{}, ", val);
            debugStr+=std::to_string(val);
        }
        return debugStr;
    }

    void checkGlobalHistogram() {
        for (int i = 0; i < 32; ++i) {
            uint32_t tmp = 0;
            for (std::uint32_t j = 0; j < row; ++j) {
                tmp += IUU.at(j)->histogram.at(i);
            }
            // spdlog::info("idx:{}, Sum:{}, Glo:{}", i, tmp, global_histogram.histogram.at(i));
        }
    }
};

uint32_t EMatrix::FLOW_HASH_SALT = 0xdeedbeef;
uint32_t EMatrix::ELEMENT_HASH_SALT = 0x123456;
uint32_t EMatrix::VALUE_HASH_SALT = 0x765432;

}

#endif
