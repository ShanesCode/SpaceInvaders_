#include "..\Headers\PauseMenuScene.h"

// Constructor
PauseMenuScene::PauseMenuScene(Game* game_) : MenuScene(game_) {
	createTitleText();
	createMenuText();
}

void PauseMenuScene::returnToPreviousScene() {
	game->popScene();
	MenuScene::mustBreak = true;
}

void PauseMenuScene::goToOptionsScene() {
	game->pushScene(new OptionsScene(game));
}

void PauseMenuScene::createTitleText() {
	float title_offset = 108.0f;
	int fontSize = 72;
	sf::Color fontColor = sf::Color::Color(165, 25, 100, 255);

	game->textManager.createText("pauseText", "title", fontSize, fontColor, "PAUSE", game->config->screenWidth / 2, (game->config->screenHeight / 4) - (title_offset / 2));
	std::string pauseText = "pauseText";
	titleTextRefsVec.push_back(pauseText);
}

void PauseMenuScene::createMenuText() {
	float text_offset = 54.0f;
	int fontSize = 36;
	sf::Color fontColor = sf::Color::Color(165, 25, 100, 255);

	game->textManager.createText("returnPause", "standard", fontSize, selectedFontColor, "RETURN", game->config->screenWidth / 2, game->config->screenHeight / 2);
	std::string returnPause = "returnPause";
	menuTextRefsVec.push_back(returnPause);

	game->textManager.createText("optionsPause", "standard", fontSize, unselectedFontColor, "OPTIONS", game->config->screenWidth / 2, (game->textManager.getTextRef(returnPause).getPosition().y + text_offset));
	std::string optionsPause = "optionsPause";
	menuTextRefsVec.push_back(optionsPause);

	game->textManager.createText("quitPause", "standard", fontSize, unselectedFontColor, "QUIT", game->config->screenWidth / 2, (game->textManager.getTextRef(optionsPause).getPosition().y + text_offset));
	std::string quitPause = "quitPause";
	menuTextRefsVec.push_back(quitPause);
}

void PauseMenuScene::selectMenuItem() {
	switch (selectedTextIndex) {
		case 0:
			// return to game
			returnToPreviousScene();
			break;
		case 1:
			// move to options scene
			goToOptionsScene();
			break;
		case 2:
			// quit game
			game->window.close();
			break;
	}
}