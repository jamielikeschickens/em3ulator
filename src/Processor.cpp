#include <memory.h>
#include "Processor.h"



namespace em3ulator {

const std::shared_ptr<Register::ITSTATE>& Processor::getITSTATEReg() {
    return _ITSTATE;
}

}
