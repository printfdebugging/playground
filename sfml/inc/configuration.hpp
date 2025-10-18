#pragma once

#include <SFML/Graphics.hpp>

#include "resourcemanager.hpp"
#include "actionmap.hpp"

class Configuration
{
public:
    Configuration()                                = delete;
    Configuration(const Configuration&)            = delete;
    Configuration& operator=(const Configuration&) = delete;

    enum Textures : int
    {
        Player,
    };

    enum PlayerInputs : int
    {
        Up,
        Left,
        Right,
        Shoot,
        Hyperspace,
    };

    enum Sounds : int
    {
        Jump,
        Boom,
        Boom2,
        SaucerSpawn2,
        Explosion,
    };

    enum Texture : int
    {
        SmallSaucer,
        BigSaucer,
        BigMeteor1,
        BigMeteor2,
        BigMeteor3,
        BigMeteor4,
    };

    static void initialize();
    static void addScore(int points);
    static int  getScore();

public:
    static ResourceManager<sf::Texture, int> textures;
    static ResourceManager<sf::Sound, int>   sounds;
    static ActionMap<int>                    player_inputs;
    static int                               lives;
    static int                               score;

private:
    static void initTextures();
    static void initPlayerInputs();
};
