#pragma once

#include "enemy.hpp"

class Saucer : public Enemy
{
public:
    Saucer(const Saucer&)            = delete;
    Saucer& operator=(const Saucer&) = delete;
    using Enemy::Enemy;

    virtual bool isCollide(const Entity& other) const;
    virtual void update(sf::Time deltaTime);
    virtual void onDestroy();
    static void  newSaucer(World& world);
};

class SmallSaucer : public Saucer
{
public:
    SmallSaucer(World& world);
    virtual int  getPoints() const;
    virtual void update(sf::Time deltaTime);

private:
    sf::Time _timeSinceLastShoot;
};

class BigSaucer : public Saucer
{
public:
    BigSaucer(World& world);
    virtual int  getPoints() const;
    virtual void update(sf::Time deltaTime);
};
