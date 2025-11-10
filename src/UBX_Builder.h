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

        //Set sync bytes
        frame.sync_1 = sync1;
        frame.sync_2 = sync2;

        //VALGET Class and ID
        frame.cls = 0x06;
        frame.id = 0x8b;

        //Push payload bytes into frame payload
        frame.payload.push_back(payload.version);
        frame.payload.push_back(payload.layers);
        UBX_Util::append_U16(frame.payload, payload.position);

        //Use append_U32 to take keys from payload and store them in frame.payload as uint8_t
        for (auto key : payload.keys){
            UBX_Util::append_U32(frame.payload, key);
        };
        
        //Get length of payload as uint16_t
        frame.length = static_cast<uint16_t>(frame.payload.size());

        //use checkSumData as data from class to end of payload for calculating check sum
        std::vector<uint8_t> checkSumData;
        checkSumData.push_back(frame.cls);
        checkSumData.push_back(frame.id);
        UBX_Util::append_U16(checkSumData, frame.length);
        checkSumData.insert(checkSumData.end(), frame.payload.begin(), frame.payload.end());

        UBX_Util::calcCheckSum(checkSumData, frame.ck_a, frame.ck_b);

        return frame;
    }

    inline UBX_Frame Build_VALSET(const UBX_CFG_VALSET_Payload& payload) {
        UBX_Frame frame;
        
        //Set sync bytes
        frame.sync_1 = sync1;
        frame.sync_2 = sync2;

        //VALSET Class and ID
        frame.cls = 0x06;
        frame.id = 0x8a;

        //Push payload bytes into frame payload
        frame.payload.push_back(payload.version);
        frame.payload.push_back(payload.layers);

        for (auto byte : payload.reserved0) {
            frame.payload.push_back(byte);
        };
        
        for (auto byte : payload.cfgData) {
            frame.payload.push_back(byte);
        };

        //get length of payload as uint16_t
        frame.length = static_cast<uint16_t>(frame.payload.size());

        std::vector<uint8_t> checkSumData;
        checkSumData.push_back(frame.cls);
        checkSumData.push_back(frame.id);
        UBX_Util::append_U16(checkSumData, frame.length);
        checkSumData.insert(checkSumData.end(), frame.payload.begin(), frame.payload.end());

        UBX_Util::calcCheckSum(checkSumData, frame.ck_a, frame.ck_b);

        return frame;
    }

    inline UBX_Frame Build_VALDEL(const UBX_CFG_VALDEL_Payload& payload) {
        UBX_Frame frame;

        //Set sync bytes
        frame.sync_1 = sync1;
        frame.sync_2 = sync2;

        //VALGET Class and ID
        frame.cls = 0x06;
        frame.id = 0x8c;

        //Push payload bytes into frame payload
        frame.payload.push_back(payload.version);
        frame.payload.push_back(payload.layers);

        for (auto byte : payload.reserved0) {
            frame.payload.push_back(byte);
        };

        //Use append_U32 to take keys from payload and store them in frame.payload as uint8_t
        for (auto key : payload.keys){
            UBX_Util::append_U32(frame.payload, key);
        };
        
        //Get length of payload as uint16_t
        frame.length = static_cast<uint16_t>(frame.payload.size());

        //use checkSumData as data from class to end of payload for calculating check sum
        std::vector<uint8_t> checkSumData;
        checkSumData.push_back(frame.cls);
        checkSumData.push_back(frame.id);
        UBX_Util::append_U16(checkSumData, frame.length);
        checkSumData.insert(checkSumData.end(), frame.payload.begin(), frame.payload.end());

        UBX_Util::calcCheckSum(checkSumData, frame.ck_a, frame.ck_b);

        return frame;
    }

};