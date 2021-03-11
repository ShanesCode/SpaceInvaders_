#pragma once
#include <SFML/Graphics.hpp>
#include "OptionsScene.h"
#include "MainMenuScene.h"
#include "MenuScene.h"

class PauseMenuScene : public MenuScene {
private:
	void returnToPreviousScene();
	void goToOptionsScene();
	void goToMainMenuScene();

	virtual void createTitleText();
	virtual void createMenuText();
	virtual void selectMenuItem();

public:
	PauseMenuScene(Game* game_);
};
