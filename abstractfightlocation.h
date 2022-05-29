#ifndef ABSTRACTFIGHTLOCATION_H
#define ABSTRACTFIGHTLOCATION_H

#include "abstractlocation.h"

class AbstractFightLocation : public AbstractLocation
{
public:
    // this method needs to be deleted, as this is an abstract class
    std::wstring getName() override { return L"Абстрактная локация для боя"; }

    void action(Player* pl) override;
};

#endif // ABSTRACTFIGHTLOCATION_H
