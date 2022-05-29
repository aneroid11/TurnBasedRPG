#ifndef FIELDLOCAT_H
#define FIELDLOCAT_H

#include "abstractlocwithpalm.h"

class FieldLocat : public AbstractLocWithPalm
{
public:
    std::wstring getName() override
    {
        return L"Поле";
    }
};

#endif // FIELDLOCAT_H
