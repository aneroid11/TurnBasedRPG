#include "appearingtext.h"

AppearingText::AppearingText(const TextParameters& params)
    : text(params.string, params.font, params.characterSize)
{
    this->secondsToAppear = 0.2f;
    this->text.setOutlineColor(sf::Color(200, 200, 200, 0));
    this->text.setOutlineThickness(1.0f);
    this->text.setPosition(params.position);

    this->text.setFillColor(sf::Color(text.getFillColor().r,
                                      text.getFillColor().g,
                                      text.getFillColor().b,
                                      0));

    this->clockSinceCreated.restart();
}

void AppearingText::update()
{
    float alphaCoef = this->clockSinceCreated.getElapsedTime().asSeconds() / this->secondsToAppear;
    unsigned currentAlpha = 170 * alphaCoef;

    if (currentAlpha > 170) { currentAlpha = 170; }

    sf::Color prevColor = this->text.getFillColor();
    this->text.setFillColor(sf::Color(prevColor.r, prevColor.g, prevColor.b, currentAlpha));
    this->text.setOutlineColor(sf::Color(prevColor.r, prevColor.g, prevColor.b, currentAlpha));
}

void AppearingText::draw(sf::RenderWindow* window)
{
    window->draw(this->text);
}
