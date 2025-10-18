#pragma once

#include "entity.hpp"

class Enemy : public Entity
{
public:
    Enemy(const Enemy&)            = delete;
    Enemy& operator=(const Enemy&) = delete;
    Enemy(Configuration::Textures textureId, World& world);

    virtual int  getPoints() const = 0;
    virtual void onDestroy();
};
