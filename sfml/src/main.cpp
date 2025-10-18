#include "game.hpp"
#include "configuration.hpp"

int main()
{
    Configuration::initialize();

    Game game;
    game.run(60);

    return 0;
}
