#include "CRSF.h"
#include "UART.h"
#include "CRC.h"


void CRSF_Send(uint8_t crsf_packet[], uint8_t length){
    Serial.write(crsf_packet, length);
    Serial.flush();
}

void CRSF_Request_ELRS_Info()
{
  uint8_t cmd_packet[8];

  cmd_packet[0] = CRSF_ADDRESS_CRSF_TRANSMITTER; 
  cmd_packet[1] = 6; 
  cmd_packet[2] = CRSF_FRAMETYPE_PARAMETER_WRITE; 
  cmd_packet[3] = CRSF_ADDRESS_CRSF_TRANSMITTER; 
  cmd_packet[4] = CRSF_ADDRESS_RADIO_TRANSMITTER; 
  cmd_packet[5] = 0;
  cmd_packet[6] = 0;
  cmd_packet[7] = Calculate_CRC(&cmd_packet[2], cmd_packet[1] - 1); 

  CRSF_Send(cmd_packet, 8);
}

void CRSF_Device_Ping()
{
  uint8_t cmd_packet[6];

  cmd_packet[0] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  cmd_packet[1] = 4; 
  cmd_packet[2] = CRSF_FRAMETYPE_DEVICE_PING;
  cmd_packet[3] = CRSF_ADDRESS_BROADCAST;
  cmd_packet[4] = CRSF_ADDRESS_RADIO_TRANSMITTER;
  cmd_packet[5] = Calculate_CRC(&cmd_packet[2], cmd_packet[1] - 1);

  CRSF_Send(cmd_packet, 6);
}