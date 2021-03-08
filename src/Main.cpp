#include "..\Headers\MainMenuScene.h"

int main()
{
    Config config("config.ini");
    Game game(&config);

    game.pushScene(new MainMenuScene(&game));
    game.gameLoop();

    return 0;
}