#include <FlexibleOperand.h>

namespace em3ulator {

FlexibleOperand::FlexibleOperand(const uint32_t immediate) : 
    type(Type::IMMEDIATE),
    immediate(immediate) {}

FlexibleOperand::FlexibleOperand(const std::shared_ptr<Register> rm) : 
    type(Type::REGISTER),
    rm(rm) {}

FlexibleOperand::FlexibleOperand(const std::shared_ptr<Register> rm,
        const ConstantShiftType shiftType, uint32_t shift) :
    type(Type::REGISTER_SHIFT_CONSTANT),
    rm(rm), constantShiftType(shiftType), immediate(shift) {}

FlexibleOperand::FlexibleOperand(const std::shared_ptr<Register> rm,
        const RegisterShiftType shiftType, uint32_t shift) :
    type(Type::REGISTER_SHIFT_REGISTER),
    rm(rm), registerShiftType(shiftType), immediate(shift) {}

uint32_t FlexibleOperand::value() {
    switch (type) {
        case Type::IMMEDIATE:
            return immediate;
        case Type::REGISTER:
            rm->value();
        case Type::REGISTER_SHIFT_CONSTANT:
            return getRegisterShiftConstantValue();
            //case Type::REGISTER_SHIFT_REGISTER:
            //    return getRegisterShiftRegisterValue();
        default:
            return 1;
    }
}

uint32_t FlexibleOperand::getRegisterShiftConstantValue() {
    switch (constantShiftType) {
        case ConstantShiftType::REGISTER_LOGICAL_SHIFT_LEFT_CONSTANT:
            return rm->value() << immediate;
        case ConstantShiftType::REGISTER_LOGICAL_SHIFT_RIGHT_CONSTANT:
            return rm->value() >> immediate;
        case ConstantShiftType::REGISTER_ARITH_SHIFT_RIGHT_CONSTANT:
            return (static_cast<int32_t>(rm->value()) >> immediate);
        case ConstantShiftType::REGISTER_ROTATE_RIGHT_CONSTANT:
            return getRegisterRotateRightConstantValue();                                                        
        default:
            return 1;
    }
}

uint32_t FlexibleOperand::getRegisterRotateRightConstantValue() {
    const uint32_t mask = 0xFFFFFFFF >> (32 - immediate);
    const uint32_t rotateBits = (rm->value() & mask) << (32 - immediate);
    return ((rm->value() >> immediate) | rotateBits);
}

}
