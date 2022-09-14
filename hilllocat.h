#ifndef HILLLOCAT_H
#define HILLLOCAT_H

#include "abstractlocwithpalm.h"

class HillLocat : public AbstractLocWithPalm
{
public:
    std::wstring getName() override
    {
        return L"Холм";
    }
};

#endif // HILLLOCAT_H
