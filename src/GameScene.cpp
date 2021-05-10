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

	playable_ySpace = 0.8f * game->config->screenHeight;
	playable_yMin = game->config->screenHeight / 2 - playable_ySpace / 2;
	playable_yMax = game->config->screenHeight / 2 + playable_ySpace / 2;
	playable_xSpace = 0.9f * game->config->screenWidth;
	playable_xMin = game->config->screenWidth / 2 - playable_xSpace / 2;
	playable_xMax = game->config->screenWidth / 2 + playable_xSpace / 2;

	move_player = false;
	move_player_right = false;
	player_width = 0;
	player_height = 0;
	player_fire = false;

	createEntities();
	InitSprites();

	clock.restart();
}

void GameScene::draw(const float dt) {
	game->window.setView(view);
	game->window.setView(guiView);

	game->window.clear(sf::Color::Black);
	drawEntities();
	drawScoreText();
}

void GameScene::update(const float dt) {
	if (move_player) {
		updatePlayerPos(dt);
	}

	if (player_fire) {
		sf::Time current_time = clock.getElapsedTime();

		if (player.previous_shot_time == sf::microseconds(0.0f)) {
			player.fire(dt, true, player_width / 2, 0, &entitiesVec);
			player.previous_shot_time = clock.getElapsedTime();
		}
		else {
			if (current_time > player.previous_shot_time + sf::seconds(player.fireRate)) {
				player.fire(dt, true, player_width / 2, 0, &entitiesVec);
				player.previous_shot_time = clock.getElapsedTime();
			}
		}
		
		player_fire = false;
	}

	for (int i = 0; i < entitiesVec.size(); i++) {
		if (typeid(*entitiesVec[i]) == typeid(Bullet)) {
			updateBulletPos(dt, entitiesVec[i], i);
		}
		else if (typeid(*entitiesVec[i]) == typeid(Saucer)) {
			updateSaucerPos(dt);
		}
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

			if (event.key.code == sf::Keyboard::Space) {
				player_fire = true;
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

void GameScene::createEntities() {
	player = PlayerShip(1, 50, 1, 50, 500, game);
	entitiesVec.push_back(&player);
	saucer = Saucer(1, 100, 0, playable_xMax, playable_yMin + saucer.sprite.getLocalBounds().height, game);
	saucer.playSound();
	entitiesVec.push_back(&saucer);
}

void GameScene::drawEntities() {
	for (int i = 0; i < entitiesVec.size(); i++) {
		game->window.draw(entitiesVec[i]->sprite);
	}
}

void GameScene::InitSprites() {
	saucer.sprite.setScale(sf::Vector2f(2.0f, 2.0f));

	// Player
	player.sprite.setScale(sf::Vector2f(2.0f, 2.0f));

	player_width = player.sprite.getLocalBounds().width * player.sprite.getScale().x;
	player_height = player.sprite.getLocalBounds().height * player.sprite.getScale().y;

	int player_start_xpos = game->config->screenWidth / 2 + player_width / 2;
	int player_start_ypos = playable_yMax - player_height;
	player.setPosition(player_start_xpos, player_start_ypos);
}

void GameScene::updatePlayerPos(const float dt) {
	// Check player is within playable space
	// If edge of player is above playable_xMin, let them move left.
	if (playable_xMin < player.xpos && !move_player_right) {
		player.move(dt, move_player_right);
	}

	// If edge of player is below playable_xMax, let them move right (account for top-left origin)
	if (player.xpos + player_width < playable_xMax && move_player_right) {
		player.move(dt, move_player_right);
	}
}

void GameScene::updateSaucerPos(const float dt) {
	if (saucer.alive) {
		saucer.move(dt);
	}
}

void GameScene::updateBulletPos(const float dt, Entity* bullet, int index) {
	// Check if bullet within playable space
	// If edge of bullet is above playable_yMin, move it down
	// Or if edge of bullet is below playable_yMin, move it down
	if (playable_yMin < bullet->ypos && bullet->ypos < playable_yMax) {
		bullet->move(dt, false);
	}
	// Else destroy the bullet and remove it from the vector of entities
	else {
		if (bullet->alive && bullet->health > 0) {
			// Set health to 0 so this is only called once per bullet
			bullet->health = 0;

			// Change to miss texture and move it left to center it (account for top-left origin)
			bullet->sprite.setTexture(game->textureManager.getRef("bullet_miss"), true);
			bullet->sprite.setPosition(bullet->sprite.getPosition().x - bullet->sprite.getLocalBounds().width / 2, bullet->sprite.getPosition().y);
			// Update the entitiesVec so that the draw call uses the new sprite
			entitiesVec[index] = bullet;

			// Start a new thread so that it can show spirte for time specified in bulletDeath() and delay deletion
			// Without causing delay in main thread execution
			std::thread waiter(&GameScene::bulletDeath, this, bullet, 0.5f);
			waiter.detach();
		}
		
		// Once specified time in bulletDeath() has passed, destroy the bullet
		if (!bullet->alive) {
			destroyEntity(bullet, index);
		}
	}
}

void GameScene::destroyEntity(Entity* entity, int index) {
	delete entity;
	entitiesVec.erase(entitiesVec.begin() + index);
}

void GameScene::waitForSeconds(float time) {
	sf::Time start_time = clock.getElapsedTime();
	sf::Time current_time = clock.getElapsedTime();
	sf::Time wait_time = sf::seconds(time);

	// While the specified time has not passed, do nothing
	while (current_time - start_time < wait_time) {
		current_time = clock.getElapsedTime();
	};
	return;
}

void GameScene::bulletDeath(Entity* bullet, float time) {
	waitForSeconds(time);
	bullet->death();
}