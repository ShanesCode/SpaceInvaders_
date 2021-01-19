#pragma once
#include "Scene.h"
#include "Config.h"
class MenuScene : public Scene {
	public:
		void createTextElements(Config &config);
		void createTitle(Config& config);
		void createMenu(Config& config);
		int navigateMenu(int input, Config& config);
		int selectedTextIndex;
		const int menuIndex;
		MenuScene(std::string sceneName_, std::string musicString_, Config& config);
};