#pragma once

#include <SFML/Graphics.hpp>
#include "configuration.hpp"
#include "world.hpp"

class Entity : public sf::Drawable
{
public:
    Entity(const Entity&)            = delete;
    Entity& operator=(const Entity&) = delete;
    Entity(Configuration::Textures textureId, World& world);
    virtual ~Entity();

    virtual bool        isAlive() const;
    const sf::Vector2f& getPosition() const;

    template <typename... Args>
    void setPosition(Args&&... args)
    {
        _sprite.setPosition(std::forward<Args>(args)...);
    }

    virtual bool isCollide(const Entity& other) const = 0;
    virtual void update(sf::Time deltaTime)           = 0;
    virtual void onDestroy();

protected:
    sf::Sprite   _sprite;
    sf::Vector2f _impulse;
    World&       _world;
    bool         _alive;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
