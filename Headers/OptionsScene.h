#pragma once
#include <SFML/Graphics.hpp>
#include "MenuScene.h"

class OptionsScene : public MenuScene {
private:
	void returnToPreviousScene();

	virtual void createTitleText();
	virtual void createMenuText();
	virtual void selectMenuItem();

	void changeVolumeSlider(bool increase);

	virtual void handleInput();

	float max_volume;
	float min_volume;

public:
	OptionsScene(Game* game_);
};