#ifndef APPEARINGBUTTON_H
#define APPEARINGBUTTON_H

#include "appearingobject.h"
#include "isubject.h"

#include <Thor/Shapes.hpp>
#include <Thor/Graphics.hpp>

#include <iostream>
#include <functional>
#include <list>

class AppearingButton : public AppearingObject, public ISubject
{
public:
    AppearingButton(std::wstring str, sf::Font& font);
    ~AppearingButton() override;

    void update(sf::Event& e, sf::RenderWindow& window) override;
    void setAlpha(unsigned alpha) override;

    sf::Vector2f getSize() const
    {
        return sf::Vector2f(this->text->getGlobalBounds().width * 1.5f,
                            this->text->getGlobalBounds().height * 1.5f);
    }

    sf::Vector2f getPosition() const { return this->text->getPosition(); }

    void setPosition(const sf::Vector2f& pos) { this->text->setPosition(pos); }

    void attachObserver(IObserver* observer) override { this->observers.push_back(observer); }
    void detachObserver(IObserver* observer) override { this->observers.remove(observer); }
    void notifyObservers(const std::wstring msg) override
    {
        for (IObserver* o : observers)
        {
            o->update(msg);
        }
    }

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    AppearingButton(const AppearingButton& other) = delete;

    sf::Text* text = nullptr;

    bool clicked;

    std::list<IObserver*> observers;
};

#endif // APPEARINGBUTTON_H
