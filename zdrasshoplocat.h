#ifndef ZDRASSHOPLOCAT_H
#define ZDRASSHOPLOCAT_H

#include "abstractshoplocat.h"

class ZdrasShopLocat : public AbstractShopLocat
{
public:
    std::wstring getName() override
    {
        return L"Zdras Shop";
    }

    void action(Player* pl) override;
};

#endif // ZDRASSHOPLOCAT_H
