#include "errorandexit.h"

#include <iostream>

void errorAndExit(std::string errMsg)
{
    std::cerr << errMsg << "\n";
    exit(-1);
}
