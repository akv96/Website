#include "memory.h"

internal_function u16
LittleToBigEndianU16(u16 V)
{
    u16 Result = 0;

    Result = (V << 8) | (V >> 8);

    return Result;
}