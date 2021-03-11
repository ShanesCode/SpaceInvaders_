#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

class MenuScene : public Scene {
public:
	sf::View view;

	sf::Color unselectedFontColor;
	sf::Color selectedFontColor;

	sf::Vector2f pos;

	std::vector<std::string> titleTextRefsVec;
	std::vector<std::string> menuTextRefsVec;

	virtual void createTitleText();
	void drawTitleText();
	virtual void createMenuText();
	void drawMenuText();
	void navigateMenu(bool downwards);
	virtual void selectMenuItem();

	int selectedTextIndex;

	bool mustBreak;

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	MenuScene(Game* game_);
};