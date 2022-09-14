#ifndef ABSTRACTFIGHTLOCATION_H
#define ABSTRACTFIGHTLOCATION_H

#include "abstractlocation.h"

class AbstractFightLocation : public AbstractLocation
{
public:
    void action(Player* pl) override;
};

#endif // ABSTRACTFIGHTLOCATION_H
