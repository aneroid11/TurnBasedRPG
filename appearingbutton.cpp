#include "appearingbutton.h"

#include <iostream>

AppearingButton::AppearingButton(std::wstring str, sf::Font& font)
    : AppearingObject(0.2f)
{
    this->text = new sf::Text(str, font);

    sf::Vector2f textSize = sf::Vector2f(text->getGlobalBounds().width, text->getGlobalBounds().height);
    float bgScaleCoef = 1.5f;
    //const float bgScaleCoef = 1.0f;
    sf::Vector2f bgSize = sf::Vector2f(textSize.x * bgScaleCoef, textSize.y * bgScaleCoef);

    this->background = new sf::ConvexShape(thor::Shapes::roundedRect(bgSize, 3.0f, sf::Color(100, 100, 100),
                                                                     1.0f, sf::Color(100, 100, 100)));

    this->background->setOrigin(this->background->getGlobalBounds().width / 2,
                                this->background->getGlobalBounds().height / 2);
    this->text->setOrigin(this->text->getGlobalBounds().width / 2,
                          this->text->getGlobalBounds().height / 2);

    const sf::FloatRect backSize = this->background->getGlobalBounds();
    const sf::FloatRect textSz = this->text->getGlobalBounds();
    std::cout << "background size: " << backSize.width << "x" << backSize.height << "\n";
    std::cout << "text size: " << textSz.width << "x" << textSz.height << "\n";

    this->text->setFillColor(sf::Color(230, 230, 230));
    this->text->setOutlineThickness(1.0f);
    this->text->setOutlineColor(sf::Color(230, 230, 230));

    this->clicked = false;
}

AppearingButton::~AppearingButton()
{
    if (this->text)
    {
        delete this->text;
    }
    if (this->background)
    {
        delete this->background;
    }
}

void AppearingButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*this->background, states);
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

            if (this->background->getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y)))
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
    sf::Color bgColor = this->background->getFillColor();
    sf::Color textColor = this->text->getFillColor();

    this->background->setFillColor(sf::Color(bgColor.r, bgColor.g, bgColor.b, alpha));
    this->background->setOutlineColor(sf::Color(bgColor.r, bgColor.g, bgColor.b, alpha));

    this->text->setFillColor(sf::Color(textColor.r, textColor.g, textColor.b, alpha));
    this->text->setOutlineColor(sf::Color(textColor.r, textColor.g, textColor.b, alpha));
}
