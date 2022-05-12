#include "appearingtext.h"

AppearingText::AppearingText(const TextParameters& params)
    : text(params.string, params.font, params.characterSize)
{
    this->currentAlpha = 200;
    this->secondsToAppear = 0.2f;
    this->text.setOutlineColor(sf::Color(200, 200, 200, this->currentAlpha));
    this->text.setOutlineThickness(1.0f);
    this->text.setPosition(params.position);

    this->text.setFillColor(sf::Color(text.getFillColor().r,
                                      text.getFillColor().g,
                                      text.getFillColor().b,
                                      this->currentAlpha));

    this->clockSinceCreated.restart();
}

void AppearingText::update()
{
    float alphaCoef = this->clockSinceCreated.getElapsedTime().asSeconds() / this->secondsToAppear;
    this->currentAlpha = 200 * alphaCoef;

    if (this->currentAlpha > 200) { this->currentAlpha = 200; }

    sf::Color prevColor = this->text.getColor();
    this->text.setFillColor(sf::Color(prevColor.r, prevColor.g, prevColor.b, this->currentAlpha));
    this->text.setOutlineColor(sf::Color(prevColor.r, prevColor.g, prevColor.b, this->currentAlpha));
}

void AppearingText::draw(sf::RenderWindow* window)
{
    window->draw(this->text);
}
