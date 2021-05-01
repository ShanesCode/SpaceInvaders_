#pragma once
#include <SFML/Graphics.hpp>
#include "PauseMenuScene.h"
#include "PlayerShip.h"

class GameScene : public Scene {
private:
	sf::View view;
	sf::View guiView;

	void pauseGame();

	std::vector<sf::Text*> scoreTextVec;
	void createScoreText();
	void drawScoreText();

	PlayerShip player;
	bool move_player;
	bool move_player_right;

	// Percentage of the window the play area should take up
	int playable_ySpace;
	int playable_xSpace;

	void InitSprites();

	void updatePlayerPos();

public:
	void draw(const float dt) override;
	void update(const float dt) override;
	void handleInput() override;

	GameScene(Game* game_);
};