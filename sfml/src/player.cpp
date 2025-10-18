#include <cmath>
#include <cstdlib>

#include "player.hpp"
#include "configuration.hpp"
#include "collision.hpp"

Player::Player(World& world)
    : Entity(Configuration::Textures::Player, world)
    , ActionTarget(Configuration::player_inputs)
    , _isMoving(false)
    , _rotation(0)
{
    bind(Configuration::PlayerInputs::Up, [this](const sf::Event&)
         { _isMoving = true; });

    bind(Configuration::PlayerInputs::Left, [this](const sf::Event&)
         { _rotation -= 1; });

    bind(Configuration::PlayerInputs::Right, [this](const sf::Event&)
         { _rotation += 1; });

    bind(Configuration::PlayerInputs::Shoot, [this](const sf::Event&)
         { shoot(); });

    bind(Configuration::PlayeInputs::Hyperspace, [this](const sf::Event&)
         { goToHyperspace(); });
}

void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    _timeSinceLastShoot += deltaTime;
    if (_rotation != 0)
    {
        float angle = _rotation * 250 * seconds;
        _sprite.rotate(angle);
    }

    if (_isMoving)
    {
        float angle = _sprite.getRotation() / 180 * M_PI - M_PI / 2;
        _impulse += sf::Vector2f(std::cos(angle), std::sin(angle)) * 300.f * seconds;
    }
    _sprite.move(seconds * _impulse);
}

void Player::shoot()
{
    if (_timeSinceLastShoot > sf::seconds(0.3))
    {
        _world.add(new ShootPlayer(*this));
        _timeSinceLastShoot = sf::Time::Zero;
    }
}

void Player::processEvents()
{
    _isMoving = false;
    _rotation = 0;
    ActionTarget::processEvents();
}

void Player::goToHyperspace()
{
    _impulse = sf::Vector2f(0, 0);
    setPosition(random(0, _world.getX()), random(0, _world.getY()));
    _world.add(Configuration::Sounds::Jump)
}

void Player::onDestroy()
{
    Entity::onDestroy();
    Configuration::lives--;
    world.add(Configuration::Sounds::Boom);
}

bool Player::isCollide(const Entity& other) const
{
    if (dynamic_cast<const ShootPlayer*>(&other) == nullptr)
    {
        return Collision::circleTest(_sprite, other._sprite);
    }
    return false;
}
