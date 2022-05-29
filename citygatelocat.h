#ifndef CITYGATELOCAT_H
#define CITYGATELOCAT_H

#include "abstractlocation.h"

class CityGateLocat : public AbstractLocation
{
public:
    std::wstring getName() override
    {
        return L"Выход из города";
    }

    void action(Player* pl) override;
};

#endif // CITYGATELOCAT_H
