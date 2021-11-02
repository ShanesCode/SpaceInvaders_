#include "../Headers/GameScene.h"

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
	game->score = 0;

	playable_ySpace = 0.8f * game->config->screenHeight;
	playable_yMin = game->config->screenHeight / 2 - playable_ySpace / 2;
	playable_yMax = game->config->screenHeight / 2 + playable_ySpace / 2;
	playable_xSpace = 0.9f * game->config->screenWidth;
	playable_xMin = game->config->screenWidth / 2 - playable_xSpace / 2;
	playable_xMax = game->config->screenWidth / 2 + playable_xSpace / 2;

	move_player = false;
	move_player_right = false;
	player_fire = false;

	createEntities();
	createBuildings();
	InitSprites();

	clock.restart();
}

void GameScene::draw(const float dt) {
	game->window.setView(view);
	game->window.setView(guiView);

	game->window.clear(sf::Color::Black);
	drawEntities();
	drawBuildings();
	drawScoreText();
}

void GameScene::update(const float dt) {
	if (move_player) {
		updatePlayerPos(dt);
	}

	if (player_fire) {
		sf::Time current_time = clock.getElapsedTime();

		if (player.previous_shot_time == sf::microseconds(0.0f)) {
			player.fire(dt, &entitiesVec);
			player.previous_shot_time = clock.getElapsedTime();
		}
		else {
			if (current_time > player.previous_shot_time + sf::seconds(player.fireRate)) {
				player.fire(dt, &entitiesVec);
				player.previous_shot_time = clock.getElapsedTime();
			}
		}
		
		player_fire = false;
	}

	for (int i = 0; i < entitiesVec.size(); i++) {
		// Check for bullet collisions
		if (typeid(*entitiesVec[i]) == typeid(Bullet)) {
			for (int j = 0; j < entitiesVec.size(); j++) {
				if (j != i && typeid(*entitiesVec[j]) != typeid(Bullet) && entitiesVec[j]->collides) {
					if (entitiesVec[i]->detectCollision(*entitiesVec[j])) {
						break;
					}
				}
			}
			updateBulletPos(dt, entitiesVec[i], i);
		}
		else if (typeid(*entitiesVec[i]) == typeid(Saucer)) {
			updateSaucerPos(dt, i);
			if (checkSaucerOffScreen(entitiesVec[i])) {
				saucer.despawn();
			}
		}
		else if (typeid(*entitiesVec[i]) == typeid(Enemy)) {
			updateEnemyPos(dt, i);
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
	
	game->textManager.createText("scoreText", "standard", fontSize, fontColor, std::to_string(game->score), scoreLabelText->getPosition().x + scoreLabelText->getGlobalBounds().width + score_number_offset, scoreLabelText->getPosition().y);
	sf::Text* scoreText = &game->textManager.getTextRef("scoreText");
	scoreTextVec.push_back(scoreText);
}

void GameScene::drawScoreText() {
	for (int i = 0; i < scoreTextVec.size(); i++) {
		game->textManager.updateTextString("scoreText", std::to_string(game->score));
		game->window.draw(*scoreTextVec[i]);
	}
}

void GameScene::createEntities() {
	player = PlayerShip(1, 175, 1, 50, 500, true, game);
	entitiesVec.push_back(&player);

	saucer = Saucer(1, 150, 0, playable_xMax, playable_yMin + saucer.sprite.getGlobalBounds().height, true, game);
	saucer.playSound();
	entitiesVec.push_back(&saucer);

	int enemy0_count = 11;
	int enemy1_count = 22;
	int enemy2_count = 22;
	Enemy enemy0 = Enemy(0, 1, 0, 0, playable_xMin + 400, playable_yMin + 100, true, 10, game);
	Enemy enemy1 = Enemy(1, 1, 0, 0, playable_xMin + 400, playable_yMin + 100, true, 20, game);
	Enemy enemy2 = Enemy(2, 1, 0, 0, playable_xMin + 400, playable_yMin + 100, true, 30, game);
	enemies.insert(enemies.end(), enemy0_count, enemy2);
	enemies.insert(enemies.end(), enemy1_count, enemy1);
	enemies.insert(enemies.end(), enemy2_count, enemy0);
}

void GameScene::createBuildings() {
	int building_count = 4;
	Building building = Building(playable_xMin, player.ypos, true, game);
	buildings.insert(buildings.end(), building_count, building);
}

void GameScene::drawEntities() {
	for (size_t i = 0; i < entitiesVec.size(); i++) {
		game->window.draw(entitiesVec[i]->sprite);
	}
}

void GameScene::drawBuildings() {
	for (size_t i = 0; i < buildingsVec.size(); i++) {
		game->window.draw(*buildingsVec[i]);
	}
}

void GameScene::InitSprites() {
	saucer.sprite.setScale(sf::Vector2f(2.0f, 2.0f));
	
	// Player
	player.sprite.setScale(sf::Vector2f(2.0f, 2.0f));

	int player_start_xpos = game->config->screenWidth / 2 + player.sprite.getGlobalBounds().width / 2;
	int player_start_ypos = playable_yMax - player.sprite.getGlobalBounds().height;
	player.setPosition(player_start_xpos, player_start_ypos);

	// Enemies
	int enemy_y_offset = 100;
	for (size_t i = 0; i < enemies.size(); i++) {
		enemies[i].sprite.setScale(sf::Vector2f(2.0f, 2.0f));
		enemies[i].setPosition(playable_xMin + (i % 11) * enemies[i].sprite.getGlobalBounds().width * 1.5f, playable_yMin + enemy_y_offset + (i / 11) * enemies[i].sprite.getGlobalBounds().height * 1.5f);
		entitiesVec.push_back(&enemies[i]);
	}

	// Buildings
	int building_y_offset = 525;
	int building_x_offset = ((playable_xMax - playable_xMin) - (buildings[0].width * buildings.size())) / (buildings.size() + 1);
	for (size_t i = 0; i < buildings.size(); i++) {
		if (i == 0) {
			buildings[i].Entity::setPosition(playable_xMin + building_x_offset, playable_yMin + building_y_offset);
		}
		else {
			buildings[i].Entity::setPosition(buildings[i - 1].xpos + buildings[0].width + building_x_offset, buildings[i - 1].ypos);
		}
		buildings[i].updateVertexPositions();

		buildingsVec.push_back(&buildings[i]);
	}
}

void GameScene::updatePlayerPos(const float dt) {
	// Check player is within playable space
	// If edge of player is above playable_xMin, let them move left.
	if (playable_xMin < player.xpos && !move_player_right) {
		player.move(dt, move_player_right);
	}

	// If edge of player is below playable_xMax, let them move right (account for top-left origin)
	if (player.xpos + player.sprite.getGlobalBounds().width < playable_xMax && move_player_right) {
		player.move(dt, move_player_right);
	}
}

void GameScene::updateSaucerPos(const float dt, int index) {
	if (saucer.alive) {
		saucer.move(dt);
	}
	else if(saucer.health > 0) {
		saucer.health = 0;
		saucer.collides = false;
		// Wait on destroyed saucer sprite then show text for points
		std::thread saucerWaiter(&GameScene::saucerDeath, this, 0.75f, index);
		saucerWaiter.detach();		
	}
}

void GameScene::updateEnemyPos(const float dt, int index) {
	if (entitiesVec[index]->alive) {
		entitiesVec[index]->move(dt);
	}
	else if (entitiesVec[index]->health > 0) {
		entitiesVec[index]->health = 0;
		entitiesVec[index]->collides = false;
		// Wait on destroyed enemy sprite then erase enemy
		std::thread enemyWaiter(&GameScene::enemyDeath, this, 0.5f, index);
		enemyWaiter.detach();
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

			// Turn off collisions for the bullet
			bullet->collides = false;

			// Change to miss texture and move it left to center it (account for top-left origin)
			bullet->sprite.setTexture(game->textureManager.getRef("bullet_miss"), true);
			bullet->sprite.setPosition(bullet->sprite.getPosition().x - bullet->sprite.getGlobalBounds().width / 2, bullet->sprite.getPosition().y);
			// Update the entitiesVec so that the draw call uses the new sprite
			entitiesVec[index] = bullet;

			// Start a new thread so that it can show sprite for time specified in bulletDeath() and delay deletion
			// Without causing delay in main thread execution
			std::thread bulletWaiter(&GameScene::bulletDeath, this, bullet, 0.5f);
			bulletWaiter.detach();
		}
	}

	// If out of bounds wait till the specified time in bulletDeath() has passed and destroy the bullet
	if (!bullet->alive) {
		destroyEntity(bullet, index);
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

void GameScene::saucerDeath(float time, int index) {
	waitForSeconds(time);

	// Draw bonus score text
	int fontSize = 16;
	sf::Color fontColor = sf::Color::Red;
	game->textManager.createText("saucerBonusText", "standard", fontSize, fontColor, std::to_string(saucer.points), saucer.xpos + saucer.sprite.getGlobalBounds().width / 2, saucer.ypos + saucer.sprite.getGlobalBounds().height / 2);
	sf::Text* saucerBonusText = &game->textManager.getTextRef("saucerBonusText");
	scoreTextVec.push_back(saucerBonusText);

	// Remove saucer from draw vec
	entitiesVec[index]->setPosition(-50, -50);

	// Wait, then remove bonus text from scoreTextVec
	waitForSeconds(time * 2);

	if (scoreTextVec.size() == 3) {
		scoreTextVec.pop_back();
	}
}

void GameScene::enemyDeath(float time, int index) {
	waitForSeconds(time);
	
	// Remove enemy from draw vec
	entitiesVec[index]->setPosition(-50, -50);
}

bool GameScene::checkSaucerOffScreen(Entity* entity) {
	if (entity->xpos + 2 * entity->sprite.getGlobalBounds().width < playable_xMin) {
		return true;
	}
	return false;
}