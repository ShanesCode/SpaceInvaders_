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

	void createTitleText() override;
	void createMenuText() override;
	void selectMenuItem() override;

	void playMenuMusic();
public:
	MainMenuScene(Game* game_);
};