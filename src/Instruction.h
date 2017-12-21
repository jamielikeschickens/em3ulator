#ifndef EM3ULATOR_INSTRUCTION_H
#define EM3ULATOR_INSTRUCTION_H

#include <string>
#include <memory>

#include <Register.h>

namespace em3ulator {
namespace Instruction {

struct FlexibleOperand {
private:
    enum class Type {
        IMMEDIATE,
        REGISTER,
        REGISTER_SHIFT_CONSTANT,
        REGISTER_SHIFT_REGISTER
    };

    enum class ConstantShiftType {
        REGISTER_LOGICAL_SHIFT_LEFT_CONSTANT,
        REGISTER_LOGICAL_SHIFT_RIGHT_CONSTANT,
        REGISTER_ARITH_SHIFT_RIGHT_CONSTANT,
        REGISTER_ROTATE_RIGHT_CONSTANT,
        REGISTER_ROTATE_RIGHT_WITH_EXTEND
    };
    enum class RegisterShiftType {
        REGISTER_LOGICAL_SHIFT_LEFT_REGISTER,
        REGISTER_LOGICAL_SHIFT_RIGHT_REGISTER,
        REGISTER_ARITH_SHIFT_RIGHT_REGISTER,
        REGISTER_ROTATE_RIGHT_REGISTER
    };
    const Type type;
    const std::shared_ptr<Register> rm;

    const ConstantShiftType constantShiftType = 
        ConstantShiftType::REGISTER_LOGICAL_SHIFT_LEFT_CONSTANT;
    const RegisterShiftType registerShiftType = 
        RegisterShiftType::REGISTER_LOGICAL_SHIFT_LEFT_REGISTER;
    const uint32_t immediate = 0;

    uint32_t getRegisterShiftConstantValue() {
        switch (constantShiftType) {
            case ConstantShiftType::REGISTER_LOGICAL_SHIFT_LEFT_CONSTANT:
                return rm->value() << immediate;
            case ConstantShiftType::REGISTER_LOGICAL_SHIFT_RIGHT_CONSTANT:
                return rm->value() >> immediate;
            case ConstantShiftType::REGISTER_ARITH_SHIFT_RIGHT_CONSTANT:
                return (static_cast<int32_t>(rm->value()) >> immediate);
            case ConstantShiftType::REGISTER_ROTATE_RIGHT_CONSTANT: {
                const uint32_t mask = 0xFFFFFFFF >> (32 - immediate);
                const rotateBits = (rm->value() | mask) << (32 - immediate);
            }
        
        }
    }

    uint32_t getRegisterShiftRegisterValue() {

    }
public:
    FlexibleOperand(const uint32_t immediate) : 
        type(Type::IMMEDIATE),
        immediate(immediate) {}

    FlexibleOperand(const std::shared_ptr<Register> rm) : 
        type(Type::REGISTER),
        rm(rm) {}

    FlexibleOperand(const std::shared_ptr<Register> rm,
        const ConstantShiftType shiftType, uint32_t shift) :
        type(Type::REGISTER_SHIFT_CONSTANT),
        rm(rm), constantShiftType(shiftType), immediate(shift) {}
        
    FlexibleOperand(const std::shared_ptr<Register> rm,
        const RegisterShiftType shiftType, uint32_t shift) :
        type(Type::REGISTER_SHIFT_REGISTER),
        rm(rm), registerShiftType(shiftType), immediate(shift) {}

    uint32_t value() {
        switch (type) {
            case Type::IMMEDIATE:
                return immediate;
            case Type::REGISTER:
                rm->value();
            case Type::REGISTER_SHIFT_CONSTANT:
                return getRegisterShiftConstantValue();
            case Type::REGISTER_SHIFT_REGISTER:
                return getRegisterShiftRegisterValue();
        }
    }
};

class Instruction {
    virtual void execute() = 0;
};

class MOV : Instruction {
    MOV(Register& r
};

}
}

#endif
