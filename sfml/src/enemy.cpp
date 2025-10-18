#include "enemy.hpp"
#include <cmath>

Enemy::Enemy(Configuration::Textures textureId, World& world)
    : Entity(textureId, world)
{
    float angle = random(0.f, 2.f * M_PI);
    _impulse    = sf::Vector2f(std::cos(angle), std::sin(angle));
}

void Enemy::onDestroy()
{
    Entity::onDestroy();
    Configuration::addScore(getPoints());
}
