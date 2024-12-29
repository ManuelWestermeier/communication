#pragma once

#include <Arduino.h>

template <typename T>
void sendValue(uint8_t pin, T value, long baudRate = 10000)
{
    auto bitSize = sizeof(T) * 8;
    // HIGH
    digitalWrite(pin, HIGH);
    delayMicroseconds((1000000 / baudRate) >> 1);
    // DATA
    for (uint8_t index = 0; index < bitSize; index++)
    {
        digitalWrite(pin, (value >> index) & 1);
        delayMicroseconds(1000000 / baudRate);
    }
    // LOW
    digitalWrite(pin, LOW);
    delayMicroseconds(1000000 / baudRate);
}