#ifndef LEADER_ZERO_H
#define LEADER_ZERO_H

#include <stdint.h> 

namespace datasketches {
    
uint32_t get_leader_zero(uint32_t hash_value);
int hllPatLen(uint32_t hash_value);

}

#endif // !LEADER_ZERO_H
