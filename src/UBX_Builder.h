#pragma once
#include <cstdint>
#include <vector>

namespace UBX_Util {
    inline void calcCheckSum(const std::vector<uint8_t>& data, uint8_t& ckA, uint8_t& ckB){
        ckA = 0;
        ckB = 0;
        for (auto byte : data) {   
            ckA += byte;
            ckB += ckA;
        }
    }
}