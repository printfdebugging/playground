#pragma once

#include <unordered_map>

#include "action.hpp"

/** action map maps actions to user inputs of type T. so now
 * the callbacks are mapped against this user type and the
 * actual events i.e. which key is pressed; are also mapped
 * against these user type actions.
 *
 * so the user defined PlayerInput::Up as isMoving = true and
 * linked PlayerInput::Up with Action(sf::Keyboard::Up). if the
 * player wants, he can link PlayerInput::Up with sf::Keyboard::W
 * and the keybinding would be changed.
 */
template <typename T = int>
class ActionMap
{
public:
    ActionMap(const ActionMap<T>&)               = delete;
    ActionMap<T>& operator=(const ActionMap<T>&) = delete;
    ActionMap()                                  = default;

    void map(const T& key, const Action& action)
    {
        _map.emplace(key, action);
    }

    const Action& get(const T& key) const
    {
        return _map.at(key);
    }

private:
    std::unordered_map<T, Action> _map;
};
