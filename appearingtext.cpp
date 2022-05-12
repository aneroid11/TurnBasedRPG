#include "appearingtext.h"

AppearingText::AppearingText(const TextParameters& params)
    : text(params.string, params.font, params.characterSize)
{
    unsigned int alpha = 200;
    this->text.setOutlineColor(sf::Color(200, 200, 200, alpha));
    this->text.setOutlineThickness(1.0f);
    this->text.setPosition(params.position);

    this->text.setFillColor(sf::Color(text.getFillColor().r,
                                      text.getFillColor().g,
                                      text.getFillColor().b,
                                      alpha));
}

void AppearingText::update()
{
}

void AppearingText::draw(sf::RenderWindow* window)
{
    window->draw(this->text);
}
