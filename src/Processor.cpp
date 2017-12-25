#include <memory.h>
#include <iostream>

#include "Processor.h"

namespace em3ulator {

Processor::Processor() :
    _ITSTATE(new Register::ITSTATE(0x0)),
    _APSR(new Register::APSR()) {}

const std::shared_ptr<Register::ITSTATE>& Processor::getITSTATEReg() const {
    return _ITSTATE;
}

const std::shared_ptr<Register::APSR>& Processor::getAPSRReg() const {
    return _APSR;
}

bool Processor::conditionPassed() const {
    uint8_t cond = _ITSTATE->currentCondition();
    bool result = false;

    // Evaluate base condition
    switch ((cond & 0x0E) >> 1) {
        case 0x00:
            result = _APSR->Z();  // EQ or NE
            break;
        case 0x01:
            result = _APSR->C();  // CS or CC
            break;
        case 0x02:
            result = _APSR->N();  // MI or PL
            break;
        case 0x03:
            result = _APSR->V();  // VS or VC
            break;
        case 0x04:
            result = (_APSR->C()) && (!_APSR->Z());  // HI or LS
            break;
        case 0x05:
            result = (_APSR->N() == _APSR->V());    // GE or LT
            break;
        case 0x06:
            result = (_APSR->N() == _APSR->V()) && (!_APSR->Z()); // GT or LE
            break;
        case 0x07:
            result = true;  // AL
            break;
    }

    // Condition flag with 111x indicate always executed
    // Otherwise invert condition if necessary
    if ((cond & 0x01) && (cond != 0x0F)) {
        result = !result;
    }

    return result;
}

}
