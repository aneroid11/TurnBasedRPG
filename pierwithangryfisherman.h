#ifndef PIERWITHANGRYFISHERMAN_H
#define PIERWITHANGRYFISHERMAN_H

#include "fishingpier.h"

class PierWithAngryFisherman : public FishingPier
{
public:
    std::wstring getName() override
    {
        return L"Рыболовный пирс #1";
    }

    void action(Player *pl) override;
};

#endif // PIERWITHANGRYFISHERMAN_H
