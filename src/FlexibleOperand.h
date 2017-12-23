#ifndef EM3ULATOR_FLEXIBLE_OPERAND
#define EM3ULATOR_FLEXIBLE_OPERAND

#include <memory>

#include <Register.h>

namespace em3ulator {

struct FlexibleOperand {
public:
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

    FlexibleOperand(const uint32_t immediate);
    FlexibleOperand(const std::shared_ptr<Register> rm);
    FlexibleOperand(const std::shared_ptr<Register> rm,
        const ConstantShiftType shiftType, uint32_t shift); 
    FlexibleOperand(const std::shared_ptr<Register> rm,
        const RegisterShiftType shiftType, uint32_t shift);

    uint32_t value();

private:
    const Type type;
    const std::shared_ptr<Register> rm;

    const ConstantShiftType constantShiftType = 
        ConstantShiftType::REGISTER_LOGICAL_SHIFT_LEFT_CONSTANT;
    const RegisterShiftType registerShiftType = 
        RegisterShiftType::REGISTER_LOGICAL_SHIFT_LEFT_REGISTER;
    const uint32_t immediate = 0;

    uint32_t getRegisterShiftConstantValue();

    uint32_t getRegisterRotateRightConstantValue();
};
}

#endif
