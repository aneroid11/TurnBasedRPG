#ifndef ABSTRACTLOCWITHPALM_H
#define ABSTRACTLOCWITHPALM_H

#include "abstractfightlocation.h"

class AbstractLocWithPalm : public AbstractFightLocation
{
public:
    // TODO: replace
    std::wstring getName() override { return L"Поле"; }

    void action(Player* pl) override;

private:
    int shakesCount = 5;
};

#endif // ABSTRACTLOCWITHPALM_H
