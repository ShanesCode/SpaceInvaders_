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
	int player_width;
	int player_height;

	// Percentage of the window the play area should take up
	int playable_ySpace;
	int playable_yMin;
	int playable_yMax;
	int playable_xSpace;
	int playable_xMin;
	int playable_xMax;

	void InitSprites();

	void updatePlayerPos(const float dt);

public:
	void draw(const float dt) override;
	void update(const float dt) override;
	void handleInput() override;

	GameScene(Game* game_);
};