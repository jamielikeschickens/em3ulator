#ifndef EM3ULATOR_INSTRUCTION_H
#define EM3ULATOR_INSTRUCTION_H

#include <string>
#include <memory>
#include <iostream>

#include <Register.h>

namespace em3ulator {


class Instruction {
    virtual void execute() = 0;
};

}

#endif
