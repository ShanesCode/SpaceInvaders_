#pragma once
#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "HiscoresScene.h"
#include "OptionsScene.h"
#include "Scene.h"

class MainMenuScene : public Scene {
private:
	sf::View view;
	void goToGameScene();
	void goToHiscoresScene();
	void goToOptionsScene();

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

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	MainMenuScene(Game* game_);
};