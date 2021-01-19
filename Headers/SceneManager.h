#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.h"
#include "MenuScene.h"
class SceneManager {
	public:
		std::string currentScene;
		
		MenuScene menuScene;
		Scene optionsScene;
		Scene hiscoresScene;
		Scene gameScene;
		Scene gameOverScene;

		std::string changeScene();

		SceneManager(Config& config);
};