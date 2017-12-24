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
    virtual void execute() = 0;
};

class LSL : public Instruction {
public:
    LSL(std::shared_ptr<Register> rd, 
        std::shared_ptr<Register> rm,
        const uint32_t imm);

    void execute();
private:
    const std::shared_ptr<Register> _rd;
    const std::shared_ptr<Register> _rm;
    const uint32_t _imm = 0;
};

}
}

#endif
