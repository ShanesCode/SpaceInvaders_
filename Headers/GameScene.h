#pragma once
#include <SFML/Graphics.hpp>
#include "PauseMenuScene.h"

class GameScene : public Scene {
private:
	sf::View view;
	sf::View guiView;

	void pauseGame();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameScene(Game* game_);
};