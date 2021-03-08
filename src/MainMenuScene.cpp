#include "..\Headers\MainMenuScene.h"

// Constructor
MainMenuScene::MainMenuScene(Game* game_) {
	game = game_;
	sf::Vector2f pos = sf::Vector2f(game->window.getSize());
	view.setSize(pos);
	pos *= 0.5f;
	view.setCenter(pos);
	std::cout << "MainMenu" << std::endl;

	game->textManager.createText("test", "title", 108, sf::Color::Color(254, 51, 47, 150), "TEST HEHEH", game->config->screenWidth / 2, (game->config->screenHeight / 4));
}

void MainMenuScene::draw(const float dt) {
	game->window.setView(view);

	game->window.clear(sf::Color::Black);
	game->window.draw(game->background);
	sf::Text text = game->textManager.getTextRef("test");
	game->window.draw(text);
}

void MainMenuScene::update(const float dt) {

}

void MainMenuScene::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed: {
				game->window.close();
				break;
			}
			case sf::Event::Resized: {
				view.setSize(event.size.width, event.size.height);
				
				game->background.setPosition(game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
				game->background.setScale(
					float(event.size.width / float(game->background.getTexture()->getSize().x)),
					float(event.size.height) / float(game->background.getTexture()->getSize().y)
				);
				break;
			}
			case sf::Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::Escape) {
					game->window.close();
				}
				else if (event.key.code == sf::Keyboard::Space) {
					loadGame();
				}
			}
			default: break;
		}
	}
}

void MainMenuScene::loadGame() {
	game->pushScene(new GameScene(game));
	std::cout << "Game" << std::endl;
}