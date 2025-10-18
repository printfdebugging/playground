#include "game.hpp"
#include <iostream>

Game::Game(int x, int y)
    : _window(sf::VideoMode(x, y), "02_Game_Archi")
    , _x(x)
    , _y(y)
{
    _player.setPosition(100, 100);
}

void Game::run(int framePerSecond)
{
    sf::Clock clock;
    sf::Time  timeSinceLastUpdate = sf::Time::Zero;
    sf::Time  TimePerFrame        = sf::seconds(1.f / framePerSecond);

    /** one iteration of this loop is called a frame. the
     *  term frames per second is the number of iterations
     *  made by this loop in one second. */
    while (_window.isOpen())
    {
        processEvents();
        timeSinceLastUpdate = clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
        }

        update(timeSinceLastUpdate);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                _window.close();
        }
    }
    _player.processEvents();
}

void Game::update(sf::Time deltaTime)
{
    _player.update(deltaTime);
    sf::Vector2f pos = _player.getPosition();

    // TODO: see this if this needs to be removed or not
    if (pos.x < 0)
    {
        pos.x = _x;
        pos.y = _y - pos.y;
    }
    else if (pos.x > _x)
    {
        pos.x = 0;
        pos.y = _y - pos.y;
    }

    if (pos.y < 0)
    {
        pos.y = _y;
    }
    else if (pos.y > _y)
    {
        pos.y = 0;
    }

    _player.setPosition(pos);
}

void Game::render()
{
    _window.clear();
    _window.draw(_player);
    _window.display();
}
