#include "saucer.hpp"
#include "collision.hpp"

#include <cmath>

bool Saucer::isCollide(const Entity& other) const
{
    if (dynamic_cast<const ShootSaucer*>(&other) == nullptr)
        return Collision::circleTest(_sprite, other._sprite);
    return false;
}

void Saucer::update(sf::Time deltaTime)
{
    float   seconds = deltaTime.asSeconds();
    Entity* near    = nullptr;

    float nearDistance = 300;
    for (Entity* entityPtr : _world.getEntities())
    {
        if (entityPtr != this and (dynamic_cast<const Meteor*>(entityPtr) or dynamic_cast<const ShootPlayer*>(entityPtr)))
        {
            float x    = getPosition().x - entityPtr->getPosition().x;
            float y    = getPosition().y - entityPtr->getPosition().y;
            float dist = std::sqrt(x * x + y * y);
            if (dist < nearDistance)
            {
                nearDistance = dist;
                near         = entityPtr;
            }
        }
    }

    if (near != nullptr)
    {
        sf::Vector2f pos      = near->getPosition() - getPosition();
        float        angleRad = std::atan2(pos.y, pos.x);
        _impulse -= sf::Vector2f(std::cos(angleRad), std::sin(angleRad)) * 300.f * seconds;
    }
    else
    {
        sf::Vector2f pos      = Configuration::player->getPosition() - getPosition();
        float        angleRad = std::atan2(pos.y, pos.x);
        _impulse += sf::Vector2f(std::cos(angleRad), std::sin(angleRad)) * 100.f * seconds;
    }

    _sprite.move(seconds * _impulse);
};

void Saucer::onDestroy()
{
    Enemy::onDestroy();
    _world.add(Configuration::Sounds::Boom2);
}

void Saucer::newSaucer(World& world)
{
    Saucer* newSaucer = nullptr;
    if (random(0.f, 1.f) > Configuration::getScore() / 40000.f)
    {
        res = new BigSaucer(world);
    }
    else
    {
        res = new SmallSaucer(world);
    }

    newSaucer->setPosition(random(0, 1) * world.getX(), random(0, 1) * world.getY());
    world.add(newSaucer);
}

SmallSaucer::SmallSaucer(World& world)
    : Saucer(Configuration::Texture::SmallSaucer, world)
{
    _timeSinceLastShoot = sf::Time::Zero;
    _world.add(Configuration::Sounds::SaucerSpawn2);
    _impulse *= 400.f;
}

/*
 * FIXME: i hate the way sfml-blueprint's author has sprinkled these
 * magic numbers all over the place, it would be nice if they
 * are moved to configuration, maybe #define them there as macros,
 * or better create integer constants.
 */
int SmallSaucer::getPoints() const
{
    return 200;
}

void SmallSaucer::update(sf::Time deltaTime)
{
    Saucer::update(deltaTime);
    _timeSinceLastShoot += deltaTime;
    if (_timeSinceLastShoot > sf::second(1.5))
    {
        if (Configuration::player != nullptr)
        {
            _world.add(new ShootSaucer(*this));
            _timeSinceLastShoot = sf::Time::Zero;
        }
    }
}

BigSaucer::BigSaucer(World& world)
    : Saucer(Configuration::Texture::BigSaucer, world)
{
    _world.add(Configuration::Sounds::SaucerSpawn2);
    _impulse *= 400.f;
}

int BigSaucer::getPoints() const
{
    return 100;
}

void BigSaucer::update(sf::Time deltaTime)
{
    Saucer::update(deltaTime);
}
