#pragma once
#include <cstdint>
#include <vector> 
#include "UBX_Struct.h"
#include "UBX_Util.h"

const uint8_t sync1 = 0xb5;
const uint8_t sync2 = 0x62;

class UBX_Builder {
public:
    inline UBX_Frame Build_VALGET(const UBX_CFG_VALGET_Payload& payload) {
        UBX_Frame frame;
        //VALGET Class and ID
        frame.cls = 0x06;
        frame.id = 0x8b;

        //Push payload bytes into frame payload
        frame.payload.push_back(payload.version);
        frame.payload.push_back(payload.layer);
        frame.payload.push_back(payload.position);
        frame.payload.push_back(0x00);

        //Use append_U32 to take keys from payload and store them in frame.payload as uint8_t
        for (auto key : payload.keys){
            UBX_Util::append_U32(frame.payload, key);
        };
        
        //Get length of payload as uint16_t
        frame.length = frame.payload.size();

        //use checkSumData as data from class to end of payload for calculating check sum
        std::vector<uint8_t> checkSumData;
        checkSumData.push_back(frame.cls);
        checkSumData.push_back(frame.id);
        UBX_Util::append_U16(checkSumData, frame.length);
        checkSumData.insert(checkSumData.end(), frame.payload.begin(), frame.payload.end());

        UBX_Util::calcCheckSum(checkSumData, frame.ck_a, frame.ck_a);

        return frame;
    }


};