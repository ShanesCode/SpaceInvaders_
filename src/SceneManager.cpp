#include "../Headers/SceneManager.h"

SceneManager::SceneManager(Config& config): 
	menuScene("menuScene", "Resource/JoeReMi Music - Title Screen Theme (chiptune).ogg", config),
	optionsScene("optionsScene", "Resource/JoeReMi Music - Title Screen Theme (chiptune).ogg", config),
	hiscoresScene("hiscoresScene", "Resource/JoeReMi Music - Title Screen Theme (chiptune).ogg", config),
	gameScene("gameScene", "Resource/JoeReMi Music - Title Screen Theme (chiptune).ogg", config),
	gameOverScene("gameoverScene", "Resource/JoeReMi Music - Title Screen Theme (chiptune).ogg", config)
{
}

// TODO make this work for all scenes
std::string SceneManager::changeScene() {
	std::string newScene = menuScene.textVector.at(menuScene.selectedTextIndex).getString();
	std::transform(newScene.begin(), newScene.end(), newScene.begin(), ::tolower);
	if (newScene == "start") {
		newScene = "gameScene";
	}
	else if (newScene == "hiscores") {
		newScene = "hiscoresScene";
	} else if (newScene == "options") {
		newScene = "optionsScene";
	}
	std::cout << "new scene: " << newScene << std::endl;
	return newScene;
}
