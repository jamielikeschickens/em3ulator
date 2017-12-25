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

    bool isInITBlock() const;
    void ITAdvance();
    bool lastInITBlock() const;
    uint8_t currentCondition() const;
private:
    uint8_t _val = 0;
};

/* Program status is reported in the 32-bit 
 * Application Program Status Register (APSR). 
 */
class APSR {
public:
    /* Negative condition code flag. 
     * Set to bit[31] of the result of the instruction. 
     * If the result is regarded as a two's complement 
     * signed integer, then N == 1 if the result is 
     * negative and N == 0 if it is positive or zero 
     */
    bool& N() { return _N; }

    /* Zero condition code flag. Set to 1 if the result 
     * of the instruction is zero, and to 0 otherwise. 
     * A result of zero often indicates an equal result 
     * from a comparison.
     */
    bool& Z() { return _Z; }

    /* Carry condition code flag. Set to 1 if the instruction 
     * results in a carry condition, for example an unsigned 
     * overflow on an addition.
     */
    bool& C() { return _C; }

    /* Overflow condition code flag. Set to 1 if the 
     * instruction results in an overflow condition, 
     * for example a signed overflow on an addition.
     */
    bool& V() { return _V; }

    /* Set to 1 if a SSAT or USAT instruction changes the 
     * input value for the signed or unsigned range 
     * of the result. In a processor that implements 
     * the DSP extension, the processor sets this bit to 
     * 1 to indicate an overflow on some multiplies. 
     * Setting this bit to 1 is called saturation.
     */
    bool& Q();
private:
    bool _N;
    bool _Z;
    bool _C;
    bool _V;
    bool _Q;
};

}
}

#endif
