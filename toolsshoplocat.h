#ifndef TOOLSSHOPLOCAT_H
#define TOOLSSHOPLOCAT_H

#include "abstractshoplocat.h"

class ToolsShopLocat : public AbstractShopLocat
{
public:
    std::wstring getName() override
    {
        return L"Магазин инструментов";
    }

    void action(Player* player) override;
};

#endif // TOOLSSHOPLOCAT_H
