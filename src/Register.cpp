#include <cstdint>
#include <Register.h>
#include <iostream>

namespace em3ulator {
namespace Register {

uint8_t& ITSTATE::value() {
    return _val;
}

bool ITSTATE::isInITBlock() {
    return (_val & 0x0F) != 0x00;
}

void ITSTATE::ITAdvance() {
    if ((_val & 0x07) == 0x00) {
        _val = 0x00;
    } else {
        // Clear bits 4:0
        const uint8_t oldVal = _val;
        _val = (_val & 0xE0);

        _val = (_val | (0x1F & (oldVal << 1)));
    }
}

bool ITSTATE::lastInITBlock() {
    return (_val & 0x0F) == 0x08;
}

}
}
