#include "meteor.hpp"
#include "collision.hpp"

#include <cmath>

bool Meteor::isCollide(const Entity& other) const
{
    if (dynamic_cast<const Meteor*>(&other) == nullptr)
    {
        return Collision::circleTest(_sprite, other._sprite);
    }
    return false;
}

void Meteor::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    _sprite.move(seconds * _impulse);
}

BigMeteor::BigMeteor(World& world)
    : Meteor((Configuration::Textures) random(Configuration::Textures::BigMeteor1, Configuration::Textures::BigMeteor4), world)
{
    _impulse *= 100.f;
}

int BigMeteor::getPoints() const
{
    return 20;
}

void BigMeteor::onDestroy()
{
    Meteor::onDestroy();
    int nb = random(2, 3);
    for (int i = 0; i < nb; ++i)
    {
        MediumMeteor* meteor = new MediumMeteor(_world);
        meteor->setPosition(getPosition());
        _world.add(meteor);
    }
    _world.add(Configuration::Sounds::Explosion);
}
