#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"

class Game
{
public:
    Game(const Game&)            = delete;
    Game& operator=(const Game&) = delete;
    Game(int x = 800, int y = 600);
    void run(int framePerSecond);

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

private:
    sf::RenderWindow _window;
    Player           _player;
    const int        _x;
    const int        _y;
};
