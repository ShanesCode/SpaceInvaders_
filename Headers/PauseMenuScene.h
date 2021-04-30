#pragma once
#include "OptionsScene.h"
#include "MainMenuScene.h"
#include "MenuScene.h"

class PauseMenuScene : public MenuScene {
private:
	void returnToPreviousScene();
	void goToOptionsScene();

	virtual void createTitleText();
	virtual void createMenuText();
	virtual void selectMenuItem();

public:
	PauseMenuScene(Game* game_);
};
