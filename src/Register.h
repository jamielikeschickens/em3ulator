#ifndef EM3ULATOR_REGISTER_H
#define EM3ULATOR_REGISTER_H

#include <cstdint>

namespace em3ulator {
namespace Register {

class Register {
public:
    Register(const uint32_t value) :
        _value(value) {}
    uint32_t& value() { return _value; }

private:
    uint32_t _value;
};

/* This register holds the If-Then execution state bits 
 * for the Thumb IT instruction. See IT on page A7-242 for 
 * a description of the IT instruction and the 
 * associated IT block
 */
class ITSTATE {
public:
    ITSTATE(const uint8_t val) : _val(val) {}

    uint8_t& value();

    bool isInITBlock();
    void ITAdvance();
    bool lastInITBlock();
private:
    uint8_t _val = 0;
};

}
}

#endif
