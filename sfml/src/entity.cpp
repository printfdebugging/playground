#include "entity.hpp"

Entity::Entity(Configuration::Textures textureId, World& world)
    : _world(world)
    , _alive(true)
{
    sf::Texture texture = Configuration::textures.get(textureId);
    _sprite.setTexture(texture);
    _sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
}

const sf::Vector2f& Entity::getPosition() const
{
    return _sprite.getPosition();
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

bool Entity::isAlive() const
{
    return _alive;
}

bool Entity::onDestroy()
{
    _alive = false;
}
