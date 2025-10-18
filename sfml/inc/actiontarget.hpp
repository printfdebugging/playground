#pragma once

#include <list>
#include <functional>
#include <SFML/Graphics.hpp>

#include "action.hpp"
#include "actionmap.hpp"

/** an action target is something which binds itself as a target
 * of some action and with each action, a functionality. so the
 * `Player` if inherits `ActionTarget` can bind various actions
 * to various functionalities on itself.
 */
template <typename T = int>
class ActionTarget
{
public:
    using FuncType = std::function<void(const sf::Event&)>;

    ActionTarget(const ActionMap<T>& map)
        : _actionMap(map)
    {
    }

    bool processEvent(const sf::Event& event) const
    {
        bool res = false;
        for (auto& action : _eventsPoll)
        {
            if (_actionMap.get(action).first == event)
            {
                action.second(event);
                res = true;
                break;
            }
        }
        return res;
    }

    void processEvents() const
    {
        for (auto& action : _eventsRealTime)
        {
            if (_actionMap.get(action.first).test())
                action.second(_actionMap.get(action.first)._event);
        }
    }

    void bind(const T& action, const FuncType& callback)
    {
        if (_actionMap.get(action)._type & Action::Type::RealTime)
            _eventsRealTime.emplace_back(action, callback);
        else
            _eventsPoll.emplace_back(action, callback);
    }

    void unbind(const T& action)
    {
        auto remove_func = [&action](const std::pair<Action, FuncType>& pair) -> bool
        {
            return pair.first == action;
        };

        if (action._type & Action::Type::RealTime)
            _eventsRealTime.remove_if(remove_func);
        else
            _eventsPoll.remove_if(remove_func);
    }

private:
    std::list<std::pair<T, FuncType>> _eventsRealTime;
    std::list<std::pair<T, FuncType>> _eventsPoll;

    const ActionMap<T>& _actionMap;
};
