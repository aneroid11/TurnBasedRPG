#ifndef CASINO_H
#define CASINO_H

#include "abstractlocation.h"

class CasinoLocat : public AbstractLocation
{
public:
    std::wstring getName() override
    {
        return L"Казино";
    }

    void action(Player* pl) override;
};

#endif // CASINO_H
