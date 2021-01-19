#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Headers/SceneManager.h"
#include "../Headers/SceneManager.h"
#include "../Headers/Scene.h"
#include "../Headers/Config.h"
#include "../Headers/MenuScene.h"

int main()
{
    #pragma region Init
    // Initialise
    Config config("config.ini");
    sf::RenderWindow window(sf::VideoMode(config.screenWidth, config.screenHeight), "Space Invaders");
    SceneManager sceneManager(config);
    sceneManager.currentScene = sceneManager.menuScene.sceneName;
    #pragma endregion

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (sceneManager.currentScene == sceneManager.menuScene.sceneName) {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        sceneManager.menuScene.selectedTextIndex = sceneManager.menuScene.navigateMenu(1, config);
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        sceneManager.menuScene.selectedTextIndex = sceneManager.menuScene.navigateMenu(2, config);
                    }
                    else if (event.key.code == sf::Keyboard::Enter) {
                        if (sceneManager.menuScene.textVector.at(sceneManager.menuScene.selectedTextIndex).getString() == "QUIT") {
                            window.close();
                        }
                        else {
                            sceneManager.changeScene();
                        }
                    }
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (std::vector<sf::Text>::iterator textIterator = sceneManager.menuScene.textVector.begin(); textIterator != sceneManager.menuScene.textVector.end(); ++textIterator) {
            window.draw(*textIterator);
        }
        window.display();
    }

    return 0;
}