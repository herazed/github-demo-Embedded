#include "stdint.h"

void SetBits(uint32_t reg, uint8_t set_bit, uint8_t pos){

    reg |= (set_bit << pos);

}

void ClearBits(uint32_t reg, uint8_t set_bit, uint8_t pos){

    reg &= ~(set_bit << pos);

}

void ToggleBits(uint32_t reg, uint8_t set_bit, uint8_t pos){

    reg ^= (set_bit << pos);

}

void InsertField(uint32_t reg, uint8_t value, uint8_t pos, uint8_t width){

    uint32_t mask = (((1 << width) - 1) << pos);
    reg &= ~mask;
    value &= ((1 << width) - 1);
    reg |= (value << pos);

}

void ExtractField(uint32_t reg, uint8_t pos, uint8_t width){
    
    reg = reg >> pos;
    reg &= ((1 << width) - 1);

}

