#ifndef APPEARINGBUTTON_H
#define APPEARINGBUTTON_H

#include "appearingobject.h"

#include <Thor/Shapes.hpp>
#include <Thor/Graphics.hpp>

class AppearingButton : public AppearingObject
{
public:
    AppearingButton(std::wstring str, sf::Font& font, sf::Vector2f position);
    ~AppearingButton() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void update(sf::Event& e, sf::RenderWindow& window) override;
    void setAlpha(unsigned alpha) override;

private:
    sf::Text text;
    sf::ConvexShape background;
};

#endif // APPEARINGBUTTON_H
