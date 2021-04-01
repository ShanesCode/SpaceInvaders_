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

	createTitleText();
	createMenuText();
	player = PlayerShip(1, 5, 1, 50, 500);
}

void GameScene::draw(const float dt) {
	game->window.setView(view);
	game->window.setView(guiView);

	game->window.clear(sf::Color::Black);
	game->window.draw(*player.spritePtr);
	drawTitleText();
	drawMenuText();
}

void GameScene::update(const float dt) {

}

void GameScene::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed: {
			game->quit();
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
}

void GameScene::createTitleText() {
	float score_x_offset = 72.0f;
	float score_y_offset = 18.0f;
	float score_number_offset = 10.0f;
	int fontSize = 32;
	sf::Color fontColor = sf::Color::White;

	game->textManager.createText("scoreLabelText", "standard", fontSize, fontColor, "Score:", score_x_offset, score_y_offset);
	sf::Text* scoreLabelText = &game->textManager.getTextRef("scoreLabelText");
	titleTextVec.push_back(scoreLabelText);
	
	game->textManager.createText("scoreText", "standard", fontSize, fontColor, "0", scoreLabelText->getPosition().x + scoreLabelText->getLocalBounds().width + score_number_offset, scoreLabelText->getPosition().y);
	sf::Text* scoreText = &game->textManager.getTextRef("scoreText");
	titleTextVec.push_back(scoreText);
}

void GameScene::drawTitleText() {
	for (int i = 0; i < titleTextVec.size(); i++) {
		game->window.draw(*titleTextVec[i]);
	}
}

void GameScene::createMenuText() {

}

void GameScene::drawMenuText() {
	for (int i = 0; i < menuTextVec.size(); i++) {
		game->window.draw(*menuTextVec[i]);
	}
}