#pragma once
#include <SFML/Graphics.hpp>

#include "Scene.h"

class PauseMenuScene : public Scene {
private:
	sf::View view;
	void returnToGame();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	PauseMenuScene(Game* game_);
};
