#include <memory.h>
#include "Processor.h"

namespace em3ulator {

const std::shared_ptr<Register::ITSTATE>& Processor::getITSTATEReg() {
    return _ITSTATE;
}

const std::shared_ptr<Register::APSR>& Processor::getASPRReg() {
    return _ASPR;
}

}
