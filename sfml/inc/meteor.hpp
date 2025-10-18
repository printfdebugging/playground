#pragma once

#include "enemy.hpp"

/*
 * Meteor is a base class for BigMeteor, MediumMeteor and
 * SmallMeteor, and thus no constructor.
 */
class Meteor : public Enemy
{
public:
    Meteor(const Meteor&)            = delete;
    Meteor& operator=(const Meteor&) = delete;

    using Enemy::Enemy;
    virtual bool isCollide(const Entity& other) const;
    virtual void update(sf::Time deltaTime);
};

class BigMeteor : public Meteor
{
public:
    BigMeteor(World& world);
    virtual int  getPoints() const;
    virtual void onDestroy();
};
