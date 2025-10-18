#include "configuration.hpp"

ResourceManager<sf::Texture, int> Configuration::textures;
ActionMap<int>                    Configuration::player_inputs;
int                               Configuration::lives = 3;
int                               Configuration::score = 0;

void Configuration::initialize()
{
    initTextures();
    initPlayerInputs();
}

void Configuration::addScore(int points)
{
    score += points;
}

int Configuration::getScore()
{
    return score;
}

void Configuration::initTextures()
{
    textures.load(Textures::Player, "assets/ship.png");
}

void Configuration::initPlayerInputs()
{
    player_inputs.map(PlayerInputs::Up, Action(sf::Keyboard::K));
    player_inputs.map(PlayerInputs::Left, Action(sf::Keyboard::H));
    player_inputs.map(PlayerInputs::Right, Action(sf::Keyboard::L));
}
