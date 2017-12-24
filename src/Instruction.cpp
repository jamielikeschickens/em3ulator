#include <memory>

#include "Register.h"
#include "Instruction.h"

namespace em3ulator {
namespace Instruction {

Instruction::Instruction(const uint32_t repr) :
    _repr(repr) {}

uint32_t Instruction::getRepr() {
    return _repr;
}

LSL::LSL(const uint32_t repr,
         const Encoding encoding,
         std::shared_ptr<Register> rd,
         std::shared_ptr<Register> rm, 
         const uint8_t imm) :
    Instruction(repr), _encoding(encoding), 
    _rd(rd), _rm(rm), _imm(imm) {}

void LSL::execute() {
    _rd->value() = _rm->value() << _imm;;
}

}
}
