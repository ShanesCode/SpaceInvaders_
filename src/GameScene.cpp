#include "..\Headers\GameScene.h"

// Constructor
GameScene::GameScene(Game* game_) {
	game = game_;
	sf::Vector2f pos = sf::Vector2f(game->window.getSize());
	view.setSize(pos);
	guiView.setSize(pos);
	pos *= 0.5f;
	view.setCenter(pos);
	guiView.setCenter(pos);
}

void GameScene::draw(const float dt) {
	game->window.setView(view);
	game->window.setView(guiView);

	game->window.clear(sf::Color::Green);
	//game->window.draw(game->background);
}

void GameScene::update(const float dt) {

}

void GameScene::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed: {
			game->window.close();
			break;
		}
		case sf::Event::Resized: {
			view.setSize(event.size.width, event.size.height);
			guiView.setSize(event.size.width, event.size.height);

			game->background.setPosition(game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
			game->background.setScale(
				float(event.size.width / float(game->background.getTexture()->getSize().x)),
				float(event.size.height) / float(game->background.getTexture()->getSize().y)
			);
			break;
		}
		case sf::Event::KeyPressed: {
			if (event.key.code == sf::Keyboard::Escape) {
				pauseGame();
			}
		}
		default: break;
		}
	}
}

void GameScene::pauseGame() {
	game->pushScene(new PauseMenuScene(game));
	std::cout << "PauseMenu" << std::endl;
}