#include "appearingtext.h"

AppearingText::AppearingText(const TextParameters& params)
    : AppearingObject(0.2f), text(params.string, params.font, params.characterSize)
{
    //this->text.setOutlineColor(sf::Color(250, 250, 10, 0));
    this->text.setOutlineColor(sf::Color(200, 200, 200, 0));
    this->text.setOutlineThickness(1.0f);
    this->text.setPosition(params.position);

    this->text.setFillColor(sf::Color(text.getOutlineColor().r,
                                      text.getOutlineColor().g,
                                      text.getOutlineColor().b,
                                      0));
}

void AppearingText::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->text, states);
}

void AppearingText::setAlpha(unsigned alpha)
{
    sf::Color cl = this->text.getFillColor();
    this->text.setFillColor(sf::Color(cl.r, cl.g, cl.b, alpha));
    this->text.setOutlineColor(sf::Color(cl.r, cl.g, cl.b, alpha));
}
