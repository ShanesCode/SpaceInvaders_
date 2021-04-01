#pragma once
#include <SFML/Graphics.hpp>
#include "PauseMenuScene.h"
#include "PlayerShip.h"

class GameScene : public Scene {
private:
	sf::View view;
	sf::View guiView;

	void pauseGame();

	std::vector<sf::Text*> titleTextVec;
	std::vector<sf::Text*> menuTextVec;

	void createTitleText();
	void drawTitleText();
	void createMenuText();
	void drawMenuText();

	PlayerShip player;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameScene(Game* game_);
};