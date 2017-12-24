#ifndef EM3ULATOR_PROCESSOR_H
#define EM3ULATOR_PROCESSOR_H

#include <memory>

#include "Register.h"

namespace em3ulator {

class Processor {
public:
    const std::shared_ptr<Register::ITSTATE>& getITSTATEReg();
    const std::shared_ptr<Register::APSR>& getASPRReg();
private:
    const std::shared_ptr<Register::ITSTATE> _ITSTATE;
    const std::shared_ptr<Register::APSR> _ASPR;
};

}

#endif
