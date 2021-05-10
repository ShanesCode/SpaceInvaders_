#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include "PauseMenuScene.h"
#include "PlayerShip.h"
#include "Saucer.h"

class GameScene : public Scene {
private:
	sf::View view;
	sf::View guiView;

	void pauseGame();

	std::vector<sf::Text*> scoreTextVec;
	void createScoreText();
	void drawScoreText();

	void createEntities();
	void drawEntities();

	PlayerShip player;
	bool move_player;
	bool move_player_right;
	int player_width;
	int player_height;
	bool player_fire;

	// Percentage of the window the play area should take up
	int playable_ySpace;
	int playable_yMin;
	int playable_yMax;
	int playable_xSpace;
	int playable_xMin;
	int playable_xMax;

	void InitSprites();

	void updatePlayerPos(const float dt);
	void updateBulletPos(const float dt, Entity* bullet, int index);
	void updateSaucerPos(const float dt);

	sf::Clock clock;

	void destroyEntity(Entity* entity, int index);
	void waitForSeconds(float time);
	void bulletDeath(Entity* bullet, float time);

	Saucer saucer;

public:
	void draw(const float dt) override;
	void update(const float dt) override;
	void handleInput() override;

	std::vector<Entity*> entitiesVec;

	GameScene(Game* game_);
};