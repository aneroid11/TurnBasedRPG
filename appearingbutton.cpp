#include "appearingbutton.h"

#include <iostream>

AppearingButton::AppearingButton(std::wstring str, sf::Font& font, sf::Vector2f position)
    : AppearingObject(0.2f)
{
    this->text = new sf::Text(str, font);

    /*sf::Vector2f textSize = sf::Vector2f(text->getGlobalBounds().width, text->getGlobalBounds().height);
    float bgScaleCoef = 2.0f;
    sf::Vector2f bgSize = sf::Vector2f(textSize.x * bgScaleCoef, textSize.y * bgScaleCoef);
    this->background = thor::Shapes::roundedRect(bgSize, 3.0f, sf::Color(100, 100, 100),
                                                 1.0f, sf::Color(100, 100, 100));

    this->background.setOrigin(this->background.getGlobalBounds().width / 2,
                               0);
    this->background.setPosition(position);*/

    this->text->setOrigin(this->text->getGlobalBounds().width/2,
                          0);
    this->text->setPosition(position);

    this->text->setFillColor(sf::Color(200, 200, 200));
    this->text->setOutlineThickness(1.0f);
    this->text->setOutlineColor(sf::Color(200, 200, 200));

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
    std::cout << "draw button\n";
    //target.draw(this->background, states);
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

            //if (this->background.getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y)))
            if (this->text->getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y)))
            {
                std::cout << "clicked on a button\n";
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
    //sf::Color bgColor = this->background.getFillColor();
    sf::Color textColor = this->text->getFillColor();

    //this->background.setFillColor(sf::Color(bgColor.r, bgColor.g, bgColor.b, alpha));
    //this->background.setOutlineColor(sf::Color(bgColor.r, bgColor.g, bgColor.b, alpha));

    this->text->setFillColor(sf::Color(textColor.r, textColor.g, textColor.b, alpha));
    this->text->setOutlineColor(sf::Color(textColor.r, textColor.g, textColor.b, alpha));
}
