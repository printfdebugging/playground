#pragma once

#include <SFML/Graphics.hpp>

#include "entity.hpp"
#include "actiontarget.hpp"

class Player : public Entity, public ActionTarget<int>
{
public:
    Player(const Player&)            = delete;
    Player& operator=(const Player&) = delete;
    Player(World& world);

    void update(sf::Time deltaTime);
    void shoot();
    void processEvents();
    void goToHyperspace();

    virtual void onDestroy();
    virtual bool isCollide(const Entity& other) const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    bool     _isMoving;
    int      _rotation;
    sf::Time _timeSinceLastShoot;
};
