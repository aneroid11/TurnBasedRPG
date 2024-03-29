#include "appearingtext.h"

#include <iostream>

AppearingText::AppearingText(TextParameters params)
    : AppearingObject(0.3f)
{
    this->text = new sf::Text(params.string, *params.font, params.characterSize);

    this->text->setOutlineColor(sf::Color(200, 200, 200, 0));
    this->text->setOutlineThickness(0.5f);
    this->text->setPosition(params.position);

    this->text->setFillColor(sf::Color(text->getOutlineColor().r,
                                       text->getOutlineColor().g,
                                       text->getOutlineColor().b,
                                       0));
}

AppearingText::~AppearingText()
{
    if (this->text)
    {
        delete this->text;
    }
}

void AppearingText::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*this->text, states);
}

void AppearingText::setAlpha(unsigned alpha)
{
    sf::Color cl = this->text->getFillColor();
    this->text->setFillColor(sf::Color(cl.r, cl.g, cl.b, alpha));
    this->text->setOutlineColor(sf::Color(cl.r, cl.g, cl.b, alpha));
}
