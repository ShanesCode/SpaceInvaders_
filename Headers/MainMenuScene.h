#pragma once
#include <SFML/Graphics.hpp>
#include "MenuScene.h"
#include "GameScene.h"
#include "HiscoresScene.h"
#include "OptionsScene.h"

class MainMenuScene : public MenuScene {
private:
	void goToGameScene();
	void goToHiscoresScene();
	void goToOptionsScene();

	virtual void createTitleText();
	virtual void createMenuText();
	virtual void selectMenuItem();

public:
	MainMenuScene(Game* game_);
};