#ifndef FORESTLOCAT_H
#define FORESTLOCAT_H

#include "abstractlocwithpalm.h"

class ForestLocat : public AbstractLocWithPalm
{
public:
    std::wstring getName() override
    {
        return L"Лес";
    }
};

#endif // FORESTLOCAT_H
