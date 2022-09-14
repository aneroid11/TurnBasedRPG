#ifndef BAYWITHBOATLOCAT_H
#define BAYWITHBOATLOCAT_H

#include "abstractlocation.h"

class BayWithBoatLocat : public AbstractLocation
{
public:
    std::wstring getName() override
    {
        return L"Бухта с лодкой";
    }

    void action(Player* pl) override;
};

#endif // BAYWITHBOATLOCAT_H
