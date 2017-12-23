#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <FlexibleOperand.h>
#include <Register.h>

namespace em3ulator {
namespace tests {

TEST(FlexibleOperand, rotateRegisterConstant3) {
    // GIVEN
    const uint32_t shift = 3;
    std::shared_ptr<Register> r = std::make_shared<Register>(0xD);
    FlexibleOperand fo(r,
        FlexibleOperand::ConstantShiftType::REGISTER_ROTATE_RIGHT_CONSTANT,
        shift);
   
    // WHEN
    const uint32_t actualValue = fo.value();

    // THEN
    const uint32_t expectedValue = 0xA0000001;
    EXPECT_EQ(expectedValue, actualValue);
}

TEST(FlexibleOperand, rotateRegisterConstant0) {
    // GIVEN
    const uint32_t shift = 0;
    std::shared_ptr<Register> r = std::make_shared<Register>(0xDEADBEEF);
    FlexibleOperand fo(r,
        FlexibleOperand::ConstantShiftType::REGISTER_ROTATE_RIGHT_CONSTANT,
        shift);
   
    // WHEN
    const uint32_t actualValue = fo.value();

    // THEN
    const uint32_t expectedValue = 0xDEADBEEF;
    EXPECT_EQ(expectedValue, actualValue);
}

TEST(FlexibleOperand, rotateRegisterConstant32) {
    // GIVEN
    const uint32_t shift = 32;
    std::shared_ptr<Register> r = std::make_shared<Register>(0xA0A0A0A0);
    FlexibleOperand fo(r,
        FlexibleOperand::ConstantShiftType::REGISTER_ROTATE_RIGHT_CONSTANT,
        shift);
   
    // WHEN
    const uint32_t actualValue = fo.value();

    // THEN
    const uint32_t expectedValue = 0xA0A0A0A0;
    EXPECT_EQ(expectedValue, actualValue);
}

}
}
