#include <SPI.h>
#include "mcp_can.h"

const int SPI_CS_PIN = 10;
MCP_CAN CAN(SPI_CS_PIN);
unsigned char messageLenght = 0;
unsigned char messageBuffer[8];
unsigned long canId = 0;

int valueSend = 0;

#define TOGGLE_READ        \
  digitalWrite(2, HIGH);   \
  digitalWrite(2, LOW);

#define NO_OF_MESSAGES                13
int MessageCanIdArray[NO_OF_MESSAGES][4] =
{
  {1473,  0, 0, 0}, // none
  {1473, 21, 1, 0}, // next
  {1473, 22, 2, 0}, // prev
  {1473, 32, 3, 0}, // mute
  {1473, 16, 4, 0}, // vol up
  {1473, 17, 5, 0}, // vol dwn
  {1473,  4, 6, 0}, // up
  {1473,  5, 7, 0}, // dwn
  {1473, 25, 8, 0}, // search
  {1473, 7, 11, 0}, // enter
  {1473, 3, 10, 0}, // left
  {1473, 2,  9, 0}, // right
  {1473, 28, 12, 0} // call
};
#define COMMAND_INDEX MessageCanIdArray[idx][3]
#define COMMAND_SEND  MessageCanIdArray[idx][2]
#define COMMAND_VALUE MessageCanIdArray[idx][1]
#define COMMAND_ID    MessageCanIdArray[idx][0]
#define NO_COMMAND	  0

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  Serial.begin(115200);
  while (CAN_OK != CAN.begin(CAN_500KBPS));
}

void loop()
{
  if (CAN_MSGAVAIL == CAN.checkReceive())
  {
    CAN.readMsgBuf(&messageLenght, messageBuffer);
    canId = CAN.getCanId();

    for (int idx = 0; idx < NO_OF_MESSAGES; idx++)
    {
      if (canId == COMMAND_ID)
      {
        if (messageBuffer[COMMAND_INDEX] == COMMAND_VALUE)
        {
          valueSend = COMMAND_SEND;
          Serial.print(valueSend, DEC);
          TOGGLE_READ;
        }
      }
    }
  }
}
