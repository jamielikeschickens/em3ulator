#ifndef EM3ULATOR_REGISTER_H
#define EM3ULATOR_REGISTER_H

#include <cstdint>

class Register {
public:
    uint32_t& value() { return _value; }

private:
    uint32_t _value;
};

#endif
