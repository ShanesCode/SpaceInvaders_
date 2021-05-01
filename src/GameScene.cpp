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

	createScoreText();

	playable_xSpace = 0.9f * game->config->screenWidth;
	playable_ySpace = 0.8f * game->config->screenHeight;

	InitSprites();
}

void GameScene::draw(const float dt) {
	game->window.setView(view);
	game->window.setView(guiView);

	game->window.clear(sf::Color::Black);
	game->window.draw(player.sprite);
	drawScoreText();
}

void GameScene::update(const float dt) {
	if (move_player) {
		player.move(dt, move_player_right);
	}
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

			if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right) {
				move_player = true;
				if (event.key.code == sf::Keyboard::Left) {
					move_player_right = false;
				}
				else if (event.key.code == sf::Keyboard::Right) {
					move_player_right = true;
				}
			}
			break;
		}
		case sf::Event::KeyReleased: {
			if (event.key.code == sf::Keyboard::Left && !move_player_right) {
				move_player = false;
			}
			else if (event.key.code == sf::Keyboard::Right && move_player_right) {
				move_player = false;
			}
		}
		default: break;
		}
	}
}

void GameScene::pauseGame() {
	game->pushScene(new PauseMenuScene(game));
}

void GameScene::createScoreText() {
	float score_x_offset = 72.0f;
	float score_y_offset = 18.0f;
	float score_number_offset = 10.0f;
	int fontSize = 32;
	sf::Color fontColor = sf::Color::White;

	game->textManager.createText("scoreLabelText", "standard", fontSize, fontColor, "Score:", score_x_offset, score_y_offset);
	sf::Text* scoreLabelText = &game->textManager.getTextRef("scoreLabelText");
	scoreTextVec.push_back(scoreLabelText);
	
	game->textManager.createText("scoreText", "standard", fontSize, fontColor, "0", scoreLabelText->getPosition().x + scoreLabelText->getLocalBounds().width + score_number_offset, scoreLabelText->getPosition().y);
	sf::Text* scoreText = &game->textManager.getTextRef("scoreText");
	scoreTextVec.push_back(scoreText);
}

void GameScene::drawScoreText() {
	for (int i = 0; i < scoreTextVec.size(); i++) {
		game->window.draw(*scoreTextVec[i]);
	}
}

void GameScene::InitSprites() {
	player = PlayerShip(1, 50, 1, 50, 500, game);
	player.sprite.setScale(sf::Vector2f(2.0f, 2.0f));
	int player_xpos = game->config->screenWidth / 2 + player.sprite.getLocalBounds().width / 2 * player.sprite.getScale().x;
	int player_ypos = playable_ySpace - player.sprite.getLocalBounds().height / 2 * player.sprite.getScale().y;
	player.setPosition(player_xpos, player_ypos);
}

void GameScene::updatePlayerPos() {

}