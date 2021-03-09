#include "..\Headers\PauseMenuScene.h"

// Constructor
PauseMenuScene::PauseMenuScene(Game* game_) {
	game = game_;
	sf::Vector2f pos = sf::Vector2f(game->window.getSize());
	view.setSize(pos);
	pos *= 0.5f;
	view.setCenter(pos);

	createTitleText();
	createMenuText();
}

void PauseMenuScene::draw(const float dt) {
	game->window.setView(view);

	game->window.clear(sf::Color::Black);
	//game->window.draw(game->background);
	drawTitleText();
	drawMenuText();
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

void PauseMenuScene::createTitleText() {
	float title_offset = 108.0f;
	int fontSize = 72;
	sf::Color fontColor = sf::Color::Color(165, 25, 100, 255);

	game->textManager.createText("pauseText", "title", fontSize, fontColor, "PAUSE", game->config->screenWidth / 2, (game->config->screenHeight / 4) - (title_offset / 2));
	sf::Text* pauseText = &(game->textManager.getTextRef("pauseText"));
	titleTextVec.push_back(pauseText);
}

void PauseMenuScene::drawTitleText() {
	for (int i = 0; i < titleTextVec.size(); i++) {
		game->window.draw(*titleTextVec[i]);
	}
}

void PauseMenuScene::createMenuText() {
	float title_offset = 108.0f;
	int fontSize = 72;
	sf::Color fontColor = sf::Color::Color(165, 25, 100, 255);
}

void PauseMenuScene::drawMenuText() {
	for (int i = 0; i < menuTextVec.size(); i++) {
		game->window.draw(*menuTextVec[i]);
	}
}