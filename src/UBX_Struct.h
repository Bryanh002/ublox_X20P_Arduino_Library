#pragma once
#include <cstdint>
#include <vector> 

struct UBX_Message {
    uint8_t cls;
    uint8_t id;
    std::vector<uint8_t> payload;
};

struct UBX_Frame{
    uint8_t sync_1;                     //Should always be 0xb5
    uint8_t sync_2;                     //Should always be 0x62
    uint8_t cls;                        //Message Class
    uint8_t id;                         //Message Id
    uint16_t length;                    //Length (N) of payload (in bytes)
    std::vector<uint8_t> payload;       //Payload (N Bytes long)
    uint8_t ck_a; 
    uint8_t ck_b;
};

struct UBX_CFG_VALGET_Payload{
    uint8_t version =  0x00;            //Message Version
    uint8_t layer = 0x01;               //Layer from which the configurations are retrieved from 0:Ram, 1:BBR, 2:Flash, 7:Default
    uint8_t position = 0x00;            //Skip this many key values before constructing output message
    std::vector<uint32_t> keys;         //Config Key ID's that are trying to be retrieved
};
