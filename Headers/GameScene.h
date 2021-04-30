#pragma once
#include <SFML/Graphics.hpp>
#include "PauseMenuScene.h"
//#include "PlayerShip.h"

class GameScene : public Scene {
private:
	sf::View view;
	sf::View guiView;

	void pauseGame();

	std::vector<sf::Text*> scoreTextVec;
	void createScoreText();
	void drawScoreText();

	//PlayerShip player;

	// Percentage of the window the play area should take up
	int playable_ySpace;
	int playable_xSpace;

	void InitSprites();

	void updatePlayerPos();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameScene(Game* game_);
};