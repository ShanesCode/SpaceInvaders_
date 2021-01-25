#pragma once
#include <SFML/Graphics.hpp>

#include "../Scene.h"

class GameScene : public Scene {
private:
	sf::View view;
	void loadGame();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameScene(Game* game);
};