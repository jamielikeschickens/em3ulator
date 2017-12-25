#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Processor.h"
#include "Register.h"

namespace em3ulator {
namespace tests {

class ConditionPassed : public ::testing::Test,
                        public ::testing::WithParamInterface<bool> {
public: 
    Processor proc;
};

TEST_P(ConditionPassed, conditionPassedEQNE) {
    // GIVEN
    auto ITSTATE = proc.getITSTATEReg();
    ITSTATE->value() = 0x01;
    auto APSR = proc.getAPSRReg();

    APSR->Z() = GetParam();

    // WHEN
    bool actualValue = proc.conditionPassed();

    // THEN
    EXPECT_EQ(GetParam(), actualValue);
}

TEST_P(ConditionPassed, conditionPassedCSCC) {
    // GIVEN
    auto ITSTATE = proc.getITSTATEReg();
    ITSTATE->value() = 0x21;
    auto APSR = proc.getAPSRReg();

    APSR->C() = GetParam();

    // WHEN
    bool actualValue = proc.conditionPassed();

    // THEN
    EXPECT_EQ(GetParam(), actualValue);
}

TEST_P(ConditionPassed, conditionPassedMIPL) {
    // GIVEN
    auto ITSTATE = proc.getITSTATEReg();
    ITSTATE->value() = 0x41;
    auto APSR = proc.getAPSRReg();

    APSR->N() = GetParam();

    // WHEN
    bool actualValue = proc.conditionPassed();

    // THEN
    EXPECT_EQ(GetParam(), actualValue);
}

TEST_P(ConditionPassed, conditionPassedVSVC) {
    // GIVEN
    auto ITSTATE = proc.getITSTATEReg();
    ITSTATE->value() = 0x61;
    auto APSR = proc.getAPSRReg();

    APSR->V() = GetParam();

    // WHEN
    bool actualValue = proc.conditionPassed();

    // THEN
    EXPECT_EQ(GetParam(), actualValue);
}

TEST_P(ConditionPassed, conditionPassedHILSSame) {
    // GIVEN
    auto ITSTATE = proc.getITSTATEReg();
    ITSTATE->value() = 0x81;
    auto APSR = proc.getAPSRReg();

    APSR->C() = GetParam();
    APSR->Z() = GetParam();

    // WHEN
    bool actualValue = proc.conditionPassed();

    // THEN
    EXPECT_FALSE(actualValue);
}

TEST_P(ConditionPassed, conditionPassedHILSDifferent) {
    // GIVEN
    auto ITSTATE = proc.getITSTATEReg();
    ITSTATE->value() = 0x81;
    auto APSR = proc.getAPSRReg();

    APSR->C() = GetParam();
    APSR->Z() = !GetParam();

    // WHEN
    bool actualValue = proc.conditionPassed();

    // THEN
    EXPECT_EQ(GetParam(), actualValue);
}

TEST_P(ConditionPassed, conditionPassedGELTSame) {
    // GIVEN
    auto ITSTATE = proc.getITSTATEReg();
    ITSTATE->value() = 0xA1;
    auto APSR = proc.getAPSRReg();

    APSR->N() = GetParam();
    APSR->V() = GetParam();

    // WHEN
    bool actualValue = proc.conditionPassed();

    // THEN
    EXPECT_TRUE(actualValue);
}

TEST_P(ConditionPassed, conditionPassedGELTDifferent) {
    // GIVEN
    auto ITSTATE = proc.getITSTATEReg();
    ITSTATE->value() = 0xA1;
    auto APSR = proc.getAPSRReg();

    APSR->N() = GetParam();
    APSR->V() = !GetParam();

    // WHEN
    bool actualValue = proc.conditionPassed();

    // THEN
    EXPECT_FALSE(actualValue);
}

TEST_F(ConditionPassed, conditionPassedAL) {
    // GIVEN
    auto ITSTATE = proc.getITSTATEReg();
    ITSTATE->value() = 0xC1;

    // WHEN
    bool actualValue = proc.conditionPassed();

    // THEN
    EXPECT_TRUE(actualValue);
}

TEST_P(ConditionPassed, invertCondition) {
    // GIVEN
    auto ITSTATE = proc.getITSTATEReg();
    auto APSR = proc.getAPSRReg();

    ITSTATE->value() = 0x11;
    APSR->Z() = GetParam();

    // WHEN
    bool actualValue = proc.conditionPassed();

    // THEN
    EXPECT_EQ(!GetParam(), actualValue);
}

INSTANTIATE_TEST_CASE_P(ProcessorTest, ConditionPassed, ::testing::Bool());

}
}
