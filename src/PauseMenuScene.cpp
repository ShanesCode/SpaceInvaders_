#include "..\Headers\PauseMenuScene.h"

// Constructor
PauseMenuScene::PauseMenuScene(Game* game_) {
	game = game_;
	sf::Vector2f pos = sf::Vector2f(game->window.getSize());
	view.setSize(pos);
	pos *= 0.5f;
	view.setCenter(pos);
}

void PauseMenuScene::draw(const float dt) {
	game->window.setView(view);

	game->window.clear(sf::Color::Magenta);
	//game->window.draw(game->background);
}

void PauseMenuScene::update(const float dt) {

}

void PauseMenuScene::handleInput() {
	bool must_break = false;
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
					returnToGame();
					must_break = true;
				}
			}
		}
		if (must_break) { break; }
	}
}

void PauseMenuScene::returnToGame() {
	game->popScene();
	std::cout << "Game" << std::endl;
}