#ifndef EM3ULATOR_PROCESSOR_H
#define EM3ULATOR_PROCESSOR_H

#include <memory>

#include "Register.h"

namespace em3ulator {

class Processor {
public:
    Processor();
    const std::shared_ptr<Register::ITSTATE>& getITSTATEReg() const;
    const std::shared_ptr<Register::APSR>& getAPSRReg() const;

    /* The ConditionPassed() function uses this condition 
     * specifier and the APSR condition flags to 
     * determine whether the instruction must be executed */
    bool conditionPassed() const;

private:
    const std::shared_ptr<Register::ITSTATE> _ITSTATE;
    const std::shared_ptr<Register::APSR> _APSR;
};

}

#endif
