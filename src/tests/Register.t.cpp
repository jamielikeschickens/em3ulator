#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Register.h>

namespace em3ulator {
namespace Register {
namespace tests {

TEST(Register_ITSTATE, isInITBlock) {
    // GIVEN
    ITSTATE r(0xA3);

    // WHEN
    bool actualValue = r.isInITBlock();

    // THEN
    EXPECT_TRUE(actualValue);
}

TEST(Register_ITSTATE, isNotInITBlock) {
    // GIVEN
    ITSTATE r(0xF0);

    // WHEN
    bool actualValue = r.isInITBlock();

    // THEN
    EXPECT_FALSE(actualValue);
}

TEST(Register_ITSTATE, entryPoint4InstructionBlockAdvance) {
    // GIVEN
    ITSTATE r(0x3F);

    // WHEN
    uint8_t expectedValue = 0x3E;
    r.ITAdvance();
    uint8_t actualValue = r.value();

    // THEN
    EXPECT_EQ(expectedValue, actualValue);
}

TEST(Register_ITSTATE, entryPoint3InstructionBlockAdvance) {
    // GIVEN
    ITSTATE r(0x8E);

    // WHEN
    uint8_t expectedValue = 0x9C;
    r.ITAdvance();
    uint8_t actualValue = r.value();

    // THEN
    EXPECT_EQ(expectedValue, actualValue);
}

TEST(Register_ITSTATE, entryPoint2InstructionBlockAdvance) {
    // GIVEN
    ITSTATE r(0xAC);

    // WHEN
    uint8_t expectedValue = 0xB8;
    r.ITAdvance();
    uint8_t actualValue = r.value();

    // THEN
    EXPECT_EQ(expectedValue, actualValue);
}

TEST(Register_ITSTATE, entryPoint1InstructionBlockAdvance) {
    // GIVEN
    // 0110 1000
    ITSTATE r(0x68);

    // WHEN
    // 0111 0000
    uint8_t expectedValue = 0x00;
    r.ITAdvance();
    uint8_t actualValue = r.value();

    // THEN
    EXPECT_EQ(expectedValue, actualValue);
}

}
}
}
