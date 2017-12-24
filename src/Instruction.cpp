#include <memory>

#include "Register.h"
#include "Instruction.h"

namespace em3ulator {
namespace Instruction {

LSL::LSL(std::shared_ptr<Register> rd,
         std::shared_ptr<Register> rm, 
         const uint32_t imm) :
    _rd(rd), _rm(rm), _imm(imm) {}

void LSL::execute() {
    _rd->value() = _rm->value() << _imm;;
}

}
}
