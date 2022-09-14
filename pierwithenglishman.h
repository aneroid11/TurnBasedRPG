#ifndef PIERWITHENGLISHMAN_H
#define PIERWITHENGLISHMAN_H

#include "fishingpier.h"

class PierWithEnglishman : public FishingPier
{
public:
    std::wstring getName() override
    {
        return L"Рыболовный пирс #3";
    }

    void action(Player *pl) override;
};

#endif // PIERWITHENGLISHMAN_H
