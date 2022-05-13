#ifndef APPEARINGBUTTON_H
#define APPEARINGBUTTON_H

#include "appearingobject.h"
#include "isubject.h"

#include <Thor/Shapes.hpp>
#include <Thor/Graphics.hpp>

#include <functional>
#include <list>

class AppearingButton : public AppearingObject, public ISubject
{
public:
    AppearingButton(std::wstring str, sf::Font& font, sf::Vector2f position);
    ~AppearingButton() override;

    void update(sf::Event& e, sf::RenderWindow& window) override;
    void setAlpha(unsigned alpha) override;

    sf::Vector2f getSize() const
    {
        return sf::Vector2f(this->background->getGlobalBounds().width,
                            this->background->getGlobalBounds().height);
    }

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
    sf::ConvexShape* background = nullptr;

    bool clicked;

    std::list<IObserver*> observers;
};

#endif // APPEARINGBUTTON_H
