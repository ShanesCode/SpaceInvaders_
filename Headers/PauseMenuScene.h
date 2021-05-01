#pragma once
#include "OptionsScene.h"
#include "MainMenuScene.h"
#include "MenuScene.h"

class PauseMenuScene : public MenuScene {
private:
	void returnToPreviousScene();
	void goToOptionsScene();

	void createTitleText() override;
	void createMenuText() override;
	void selectMenuItem() override;

public:
	PauseMenuScene(Game* game_);
};
