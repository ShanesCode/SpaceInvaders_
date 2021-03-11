#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

class OptionsScene : public Scene {
private:
	sf::View view;

	sf::Color unselectedFontColor;
	sf::Color selectedFontColor;

	std::vector<std::string> titleTextRefsVec;
	std::vector<std::string> menuTextRefsVec;

	void createTitleText();
	void drawTitleText();
	void createMenuText();
	void drawMenuText();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	OptionsScene(Game* game_);
};