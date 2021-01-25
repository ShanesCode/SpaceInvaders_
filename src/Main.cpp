#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Headers/Game.h"
#include "../Headers/Scene.h"
#include "../Headers/Config.h"
#include "../Headers/Scenes/MainMenuScene.h"

int main()
{
    Config config("config.ini");
    Game game(config);

    game.pushScene(new MainMenuScene(&game));
    game.gameLoop();

    return 0;
}