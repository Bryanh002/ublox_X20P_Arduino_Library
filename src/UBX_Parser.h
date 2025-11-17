#pragma once
#include "UBX_Struct.h"
#include "UBX_Util.h"

class UBX_Parser {

private:

    enum ParseState {
        WAIT_SYNC1,
        WAIT_SYNC2,
        READ_HEADER,
        READ_PAYLOAD,
        READ_CKA,
        READ_CKB
    };

    ParseState state = WAIT_SYNC1;
    UBX_Frame frame;
    uint16_t payloadIndex = 0;
    std::vector<uint8_t> checksumData;

public:

    bool parseByte(uint8_t byte) {
        switch (state) {
        case WAIT_SYNC1:
            if (byte == 0xB5) {
                state = WAIT_SYNC2;
                frame.sync_1 = byte;
            }
            break;
        
        case WAIT_SYNC2:
            if (byte == 0x62) {
                state = READ_HEADER;
                frame.sync_2 = byte;
                checksumData.clear();
            } else {
                state = WAIT_SYNC1;
            }
            break;
        
        case READ_HEADER:
            checksumData.push_back(byte);
            if (checksumData.size() == 4) {
                frame.cls = checksumData[0];
                frame.id = checksumData[1];
                frame.length = static_cast<uint16_t>(checksumData[2] | (checksumData[3] << 8));
                frame.payload.clear();
                payloadIndex = 0;
                state = READ_PAYLOAD;
            }
            break;
        
        case READ_PAYLOAD:
            frame.payload.push_back(byte);
            if (++payloadIndex >= frame.length) state = READ_CKA;
            break;
        
        case READ_CKA:
            frame.ck_a = byte;
            state = READ_CKB;
            break;
        
        case READ_CKB:
            frame.ck_b = byte;
            
            //Verify checksum
            std::vector<uint8_t> verifyFrame;
            UBX_Util::createCheckSumData(frame, verifyFrame);

            uint8_t calcA, calcB;
            UBX_Util::calcCheckSum(verifyFrame, calcA, calcB);

            bool valid = (calcA == frame.ck_a && calcB == frame.ck_b);
            state = WAIT_SYNC1;
            return valid;
        }
        return false;
    }

    UBX_Frame getFrame() const { return frame; }
};