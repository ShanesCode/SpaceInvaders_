#pragma once
#include <SFML/Graphics.hpp>

#include "Scene.h"

class HiscoresScene : public Scene {
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
	void draw(const float dt) override;
	void update(const float dt) override;
	void handleInput() override;

	HiscoresScene(Game* game_);
};