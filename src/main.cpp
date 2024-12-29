#include <Arduino.h>

#include "./config.hpp" // This imports the IS_SENDING flag
#include "./node/node.hpp"

void setup()
{
  // serial
  Serial.begin(115200);
  Serial.println(IS_SENDING ? "SENDER" : "RECEIVER");

  // init
  pinMode(SEND_PIN, OUTPUT);
  pinMode(RECEIVE_PIN, INPUT);

  // sender delay
  if (IS_SENDING)
    delay(1000);
}

void loop()
{
  if (IS_SENDING)
  {
    sendValue<uint8_t>(25 + IS_SENDING, 123, BAUD_RATE);
    delay(1);
  }
  else
  {
    uint8_t received = receiveValue<uint8_t>(25 + !IS_SENDING, BAUD_RATE);
    if (received != 123)
      Serial.println(received);
  }
}