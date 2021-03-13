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

public:
	OptionsScene(Game* game_);
};