#include "CRC.h"

void Setup_CRC_Table(){
    for(int i = 0 ; i < 256 ; i++){
        uint8_t crc = i;
        for (uint8_t j = 0; j < 8; j++)
        {
            if (crc & 0x80)
            {
                crc = (crc << 1) ^ 0xD5;
            }
            else
            {
                crc <<= 1;
            }
        }
        crc8_table[i] = crc & 0xff;
    }
}

uint8_t Calculate_CRC(uint8_t *data, uint8_t length){
    uint8_t crc = 0;
    while (length--)
    {
        crc = crc8_table[crc ^ *data++];
    }
    return crc;
}