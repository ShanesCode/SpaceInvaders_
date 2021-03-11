#pragma once
#include <SFML/Graphics.hpp>
#include "OptionsScene.h"
#include "MainMenuScene.h"
#include "Scene.h"

class PauseMenuScene : public Scene {
private:
	sf::View view;

	void returnToPreviousScene();
	void goToOptionsScene();
	void goToMainMenuScene();

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

	bool must_break;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	PauseMenuScene(Game* game_);
};
