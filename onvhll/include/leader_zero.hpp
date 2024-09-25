#ifndef LEADER_ZERO_HPP
#define LEADER_ZERO_HPP

#include <stdint.h> 
namespace datasketches {

#define HLL_Q 30

uint32_t get_leader_zero(uint32_t hash_value) {
    uint32_t mask = 1;
    uint32_t cnt = 1;
    // uint32_t(int)为4字节长度，sizeof(hash_value) * 8 共32bit
    for ( uint32_t i = 0; i < sizeof(hash_value) * 8; i++) {
        // 找到hash value二进制串最右的1的位置
        if ((mask & hash_value) != 0){
            break;
        }
        mask <<= 1;
        cnt++;
    }
    if (cnt >= 32) {
        cnt = 31;
    }
    // 返回值cnt的范围是1-31，可以在5bit内表示
    return cnt;
}

int hllPatLen(uint32_t hash) {
    uint32_t bit;
    int count;

    hash |= ((uint32_t)1<<HLL_Q);

    bit = 1;
    count = 1; /* Initialized to 1 since we count the "00000...1" pattern. */
    while((hash & bit) == 0) {
        count++;
        bit <<= 1;
    }
    return count;
}

}
#endif // !LEADER_ZERO_HPP