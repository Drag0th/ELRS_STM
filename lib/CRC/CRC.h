#pragma once
#include <stdint.h>

// CRC-8/DVB-S2

uint8_t crc8_table[256];
void Setup_CRC_Table();
uint8_t Calculate_CRC( uint8_t *data, uint8_t length);
