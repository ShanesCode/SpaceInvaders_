#pragma once
#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "Scene.h"

class MainMenuScene : public Scene {
private:
	sf::View view;
	void loadGame();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	MainMenuScene(Game* game_);
};