#ifndef FISHINGPIER_H
#define FISHINGPIER_H

#include "abstractlocation.h"

class FishingPier : public AbstractLocation
{
public:
    std::wstring getName() override
    {
        return L"Рыбацкий пирс";
    }

    void action(Player* pl) override;
};

#endif // FISHINGPIER_H
