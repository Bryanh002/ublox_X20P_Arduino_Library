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

    inline void append_U16(std::vector<uint8_t>& buffer, uint32_t value){
        buffer.push_back(static_cast<uint8_t>(value & 0xFF));
        buffer.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));
    }

    inline void append_U32(std::vector<uint8_t>& buffer, uint32_t value){
        buffer.push_back(static_cast<uint8_t>(value & 0xFF));
        buffer.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));
        buffer.push_back(static_cast<uint8_t>((value >> 16) & 0xFF));
        buffer.push_back(static_cast<uint8_t>((value >> 24) & 0xFF));
    }

}