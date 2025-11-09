#pragma once
#include <cstdint>
#include <vector> 

struct UBXMessage {
    uint8_t cls;
    uint8_t id;
    std::vector<uint8_t> payload;
};

struct UBXFrame{
    uint8_t sync_1; //Should always be 0xb5
    uint8_t sync_2; //Should always be 0x62
    uint8_t cls; //Message Class
    uint8_t id; //Message Id
    uint16_t length; //Length (N) of payload (in bytes)
    std::vector<uint8_t> payload; //Payload (N Bytes long)
    uint8_t ck_a; 
    uint8_t ck_b;
};


