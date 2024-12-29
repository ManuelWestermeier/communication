#pragma once

#include <Arduino.h>

template <typename T>
T receiveValue(uint8_t pin, long baudRate = 10000)
{
    auto bitSize = sizeof(T) * 8;
    while (digitalRead(pin) != HIGH)
    {
    }
    delayMicroseconds(1000000 / baudRate);

    T value = 0;
    for (uint8_t index = 0; index < bitSize; index++)
    {
        value |= digitalRead(pin) << index;
        delayMicroseconds(1000000 / baudRate);
    }
    delayMicroseconds(1000000 / baudRate);

    return value;
}