#pragma once
#include <stdint.h>

// CRC-8/DVB-S2

class CRC_8{
    private:
        uint8_t crc8_table[256];
    public:
        void setup_CRC_table();
        uint8_t calculate( uint8_t *data, uint8_t length);
};