#ifndef PIERWITHGOODFISHERMAN_H
#define PIERWITHGOODFISHERMAN_H

#include "fishingpier.h"

class PierWithGoodFisherman : public FishingPier
{
public:
    std::wstring getName() override
    {
        return L"Рыболовный пирс #2";
    }

    void action(Player *pl) override;
};

#endif // PIERWITHGOODFISHERMAN_H
