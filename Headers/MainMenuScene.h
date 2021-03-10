#pragma once
#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "Scene.h"

class MainMenuScene : public Scene {
private:
	sf::View view;
	void loadGame();

	sf::Color unselectedFontColor;
	sf::Color selectedFontColor;

	std::vector<std::string> titleTextRefsVec;
	std::vector<std::string> menuTextRefsVec;

	void createTitleText();
	void drawTitleText();
	void createMenuText();
	void drawMenuText();
	void navigateMenu(bool downwards);
	void selectMenuItem();

	int selectedTextIndex;
	const int menuIndex;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	MainMenuScene(Game* game_);
};