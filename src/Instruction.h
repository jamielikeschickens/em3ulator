#ifndef EM3ULATOR_INSTRUCTION_H
#define EM3ULATOR_INSTRUCTION_H

#include <string>
#include <memory>
#include <iostream>

#include <Register.h>

namespace em3ulator {
namespace Instruction {

using Register::Register;

class Instruction {
public:
    Instruction(const uint32_t repr);
    virtual void execute() = 0;
    uint32_t getRepr();
private:
    const uint32_t _repr;
};

class LSL : public Instruction {
public:
    enum class Encoding {
        T1,
        T2
    };

    LSL(const uint32_t repr,
        const Encoding encoding,
        std::shared_ptr<Register> rd, 
        std::shared_ptr<Register> rm,
        const uint8_t imm);

    void execute();
private:
    const Encoding _encoding;
    const std::shared_ptr<Register> _rd;
    const std::shared_ptr<Register> _rm;
    const uint8_t _imm = 0;
};

}
}

#endif
