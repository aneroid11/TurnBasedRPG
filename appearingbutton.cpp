#include "appearingbutton.h"

#include <iostream>

AppearingButton::AppearingButton(std::wstring str, sf::Font& font)
    : AppearingObject(0.3f)
{
    this->text = new sf::Text(str, font);
    this->text->setOrigin(this->text->getGlobalBounds().width / 2,
                          0);

    this->text->setFillColor(sf::Color(230, 230, 230));
    this->text->setOutlineThickness(0.5f);
    this->text->setOutlineColor(sf::Color(230, 230, 230));

    this->clicked = false;
}

AppearingButton::~AppearingButton()
{
    if (this->text)
    {
        delete this->text;
    }
}

void AppearingButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*this->text, states);
}

void AppearingButton::update(sf::Event& event, sf::RenderWindow& window)
{
    AppearingObject::update(event, window);

    if (event.type == sf::Event::MouseButtonPressed && !this->clicked)
    {
        this->clicked = true;

        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (this->text->getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y)))
            {
                this->notifyObservers(this->text->getString().toWideString());
            }
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased)
    {
        this->clicked = false;
    }
}

void AppearingButton::setAlpha(unsigned alpha)
{
    sf::Color textColor = this->text->getFillColor();

    this->text->setFillColor(sf::Color(textColor.r, textColor.g, textColor.b, alpha));
    this->text->setOutlineColor(sf::Color(textColor.r, textColor.g, textColor.b, alpha));
}
