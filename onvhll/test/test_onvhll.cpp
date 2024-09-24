#include "On_vHLL.hpp"
#include "CardinalityMap.hpp"
#include "xxhash32.h"

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <vector>

#ifdef TEST_BINARY_INPUT_PATH
static std::string testBinaryInputPath = TEST_BINARY_INPUT_PATH;
#else
static std::string testBinaryInputPath = "test/";
#endif



std::random_device rd;

// spdlog::level::level_enum log_level = spdlog::level::info;

const uint32_t STAGE_NUM = 4;
const uint32_t STAGE_ROW = 8192;
const uint32_t STAGE_COL = 8192;

const size_t REPEAT_TIME = 1;
const uint32_t MASTER_SEED = rd();

const int LOWER_BOUND_FILTER = 10;

namespace datasketches {

void task_function(std::string &data_path, std::string &groundtruth_path, uint32_t seed) {
    On_vHLL sketch(STAGE_NUM, STAGE_ROW, STAGE_COL, seed);
    std::ifstream infs(data_path);
    std::ifstream true_infs(groundtruth_path);
    int true_card = 0;
    double est_card;
    double r_err;
    std::string src_ip;
    std::string dst_ip;
    if (!infs) {
        // spdlog::error("open {} fail", data_path);
        infs.close();
        true_infs.close();
    }

    for (size_t round = 0; round < REPEAT_TIME; ++round) {
        sketch.resetSketch();
        sketch.resetSeed(XXHash32::hash(&round, sizeof(round), seed ^ MASTER_SEED));

        infs.clear();
        infs.seekg(0);
        true_infs.clear();
        true_infs.seekg(0);
        // spdlog::info("task:{} round:{}/{}", seed, round, REPEAT_TIME);

        while (infs.good()) {
            infs >> src_ip >> dst_ip;
//            spdlog::info("{} -> {}", src_ip, dst_ip);
            if (infs.eof())
                break;
            sketch.offerFlow(src_ip.c_str(), src_ip.length(),
                             dst_ip.c_str(),dst_ip.length());
        }

        while (true_infs.good()) {
            true_infs >> src_ip >> true_card;
            if (true_infs.eof())
                break;
            if (true_card < LOWER_BOUND_FILTER)
                continue;
            est_card = sketch.decodeFlow(src_ip.c_str(), src_ip.length());
            r_err = get_r_error((double)true_card, est_card);
            // spdlog::info("{} => est:{}, true:{}, r_err:{}", src_ip, est_card, true_card, r_err);

        }
    }
    infs.close();
    true_infs.close();
}

int main() {
    std::string input = "~/data/onvhll/130500.uniq";
    std::string ground_truth = "~/data/onvhll/130500.grouptruth";
    task_function(input, ground_truth, 45);
    return 0;
}

} /* namespace datasketches */