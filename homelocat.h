#ifndef HOMELOCAT_H
#define HOMELOCAT_H

#include "abstractlocation.h"

class HomeLocat : public AbstractLocation
{
public:
    std::wstring getName() override
    {
        return L"Дом";
    }

    void action(Player* player);
};

#endif // HOMELOCAT_H
