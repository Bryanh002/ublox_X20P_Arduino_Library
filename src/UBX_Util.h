#pragma once
#include <cstdint>
#include <vector>
#include "UBX_Struct.h"

namespace UBX_Util {
    inline void calcCheckSum(const std::vector<uint8_t>& data, uint8_t& ckA, uint8_t& ckB){
        ckA = 0;
        ckB = 0;
        for (auto byte : data) {   
            ckA += byte;
            ckB += ckA;
        }
    }

    inline void createCheckSumData(const UBX_Frame& frame, std::vector<uint8_t>& checkSumData){
        checkSumData.clear();
        checkSumData.push_back(frame.cls);
        checkSumData.push_back(frame.id);
        append_U16(checkSumData, frame.length);
        checkSumData.insert(checkSumData.end(), frame.payload.begin(), frame.payload.end());
    }

    inline void append_U16(std::vector<uint8_t>& buffer, uint16_t value){
        buffer.push_back(static_cast<uint8_t>(value & 0xFF));               //LSB
        buffer.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));        //MSB
    }

    inline void append_U32(std::vector<uint8_t>& buffer, uint32_t value){
        buffer.push_back(static_cast<uint8_t>(value & 0xFF));               // Byte 0
        buffer.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));        // Byte 1
        buffer.push_back(static_cast<uint8_t>((value >> 16) & 0xFF));       // Byte 2
        buffer.push_back(static_cast<uint8_t>((value >> 24) & 0xFF));       // Byte 3
    }
}