#pragma once

#include <list>
#include "configuration.hpp"

class Entity;
class Configuration;

class World : public sf::Drawable
{
public:
    World(const World&)            = delete;
    World& operator=(const World&) = delete;
    World(float x, float y);
    ~World();

    void add(Entity* entity);
    void clear();
    bool isCollide(const Entity& other);
    int  size() const;

    void                     add(Configuration::Sounds soundId);
    const std::list<Entity*> getEntities() const;
    int                      getX() const;
    int                      getY() const;
    void                     update(sf::Time deltaTime);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    std::list<Entity*>                    _entities;
    std::list<Entity*>                    _tmp_entities;
    std::list<std::unique_ptr<sf::Sound>> _sounds;
    int                                   _x;
    int                                   _y;
};
