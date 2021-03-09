#pragma once
#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "Scene.h"

class MainMenuScene : public Scene {
private:
	sf::View view;
	void loadGame();

	std::vector<sf::Text*> titleTextVec;
	std::vector<sf::Text*> menuTextVec;

	void createTitleText();
	void drawTitleText();
	void createMenuText();
	void drawMenuText();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	MainMenuScene(Game* game_);
};