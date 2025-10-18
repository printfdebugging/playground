#pragma once

#include <SFML/Graphics.hpp>

/** an action represents just one instruction, whether it be form
 * the keyboard or using the mouse. class Action on it's own just
 * represents that, and has various utilities to compare an instance
 * of itself with another instance, or an SFML event. it can also
 * whether the action (input) is real time or not through the
 * test() function
 */
class Action
{
public:
    enum Type
    {
        RealTime = 1,
        Pressed  = 1 << 1,
        Released = 1 << 2,
    };

    Action(const sf::Keyboard::Key& key, int type = Type::RealTime | Type::Pressed);
    Action(const sf::Mouse::Button& button, int type = Type::RealTime | Type::Pressed);
    Action(const Action& other);

    bool    test() const;
    bool    operator==(const sf::Event& event) const;
    bool    operator==(const Action& other) const;
    Action& operator=(const Action& other);

private:
    template <typename T>
    friend class ActionTarget;
    sf::Event _event;
    int       _type;
};
