#include <cstdint>
#include <iostream>
#include <exception>

#include <Register.h>

namespace em3ulator {
namespace Register {

uint8_t& ITSTATE::value() {
    return _val;
}

bool ITSTATE::isInITBlock() const {
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

bool ITSTATE::lastInITBlock() const {
    return (_val & 0x0F) == 0x08;
}

uint8_t ITSTATE::currentCondition() const {
    if ((_val & 0x0F) != 0x00) {
        return (_val & 0xF0) >> 4;
    } else if (_val == 0x00) {
        return 0x0E;
    }

    throw std::runtime_error("INSTRUCTION EXECUTION UNPREDICTABLE");
}

}
}
