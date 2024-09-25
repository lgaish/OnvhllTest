#include "On_vHLL.hpp"
#include "CardinalityMap.hpp"
#include "xxhash32.h"
#include <catch2/catch.hpp>
#include <fstream>
#include <sstream>
#include <stdexcept>

#ifdef TEST_BINARY_INPUT_PATH
static std::string testBinaryInputPath = TEST_BINARY_INPUT_PATH;
#else
static std::string testBinaryInputPath = "test/";
#endif

namespace datasketches
{

    std::random_device rd;

    // spdlog::level::level_enum log_level = spdlog::level::info;
    const uint32_t STAGE_NUM = 4;
    const uint32_t STAGE_ROW = 8192;
    const uint32_t STAGE_COL = 8192;
    const size_t REPEAT_TIME = 1;
    const uint32_t MASTER_SEED = rd();
    const int LOWER_BOUND_FILTER = 10;

    TEST_CASE("on_vhll test", "on_vhll")
    {
        std::string data_path = "../../datasets/on_vhll/uniq/test.uniq";
        std::string groundtruth_path = "../../datasets/on_vhll/groundtruth/test.groundtruth";
        uint32_t seed = 45;
        On_vHLL sketch(STAGE_NUM, STAGE_ROW, STAGE_COL, seed);

        // 文件流创建
        std::ifstream infs(data_path);
        std::ifstream true_infs(groundtruth_path);
        if (!infs)
        {
            infs.close();
            true_infs.close();
        }
        REQUIRE(!infs); // 文件流创建失败
        if (!true_infs)
        {
            infs.close();
            true_infs.close();
        }
        REQUIRE(!true_infs); // 文件流创建失败
        infs.clear();
        infs.seekg(0);
        true_infs.clear();
        true_infs.seekg(0);

        // 执行on_vhll算法
        std::string src_ip;
        std::string dst_ip;
        size_t round = 0;
        int true_card = 0;
        double est_card;
        double r_err;
        sketch.resetSketch();
        sketch.resetSeed(XXHash32::hash(&round, sizeof(round), seed ^ MASTER_SEED));
        while (infs.good())
        {
            infs >> src_ip >> dst_ip;
            if (infs.eof())
                break;
            sketch.offerFlow(src_ip.c_str(), src_ip.length(),
                             dst_ip.c_str(), dst_ip.length());
        }
        while (true_infs.good())
        {
            true_infs >> src_ip >> true_card;
            if (true_infs.eof())
                break;
            if (true_card < LOWER_BOUND_FILTER)
                continue;
            est_card = sketch.decodeFlow(src_ip.c_str(), src_ip.length());
            r_err = get_r_error((double)true_card, est_card);
            REQUIRE(r_err < 100);
            // spdlog::info("{} => est:{}, true:{}, r_err:{}", src_ip, est_card, true_card, r_err);
        }
        infs.close();
        true_infs.close();
    }

} /* namespace datasketches */