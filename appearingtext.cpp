#include "appearingtext.h"

AppearingText::AppearingText(const TextParameters& params)
    : text(params.string, params.font, params.characterSize), AppearingObject(0.2f)
{
    //this->text.setOutlineColor(sf::Color(250, 250, 10, 0));
    this->text.setOutlineColor(sf::Color(150, 150, 150, 0));
    this->text.setOutlineThickness(1.0f);
    this->text.setPosition(params.position);

    this->text.setFillColor(sf::Color(text.getOutlineColor().r,
                                      text.getOutlineColor().g,
                                      text.getOutlineColor().b,
                                      0));
}

void AppearingText::draw(sf::RenderWindow* window)
{
    window->draw(this->text);
}

void AppearingText::setAlpha(unsigned alpha)
{
    sf::Color cl = this->text.getFillColor();
    this->text.setFillColor(sf::Color(cl.r, cl.g, cl.b, alpha));
    this->text.setOutlineColor(sf::Color(cl.r, cl.g, cl.b, alpha));
}
