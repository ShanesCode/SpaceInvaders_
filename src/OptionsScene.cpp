#include "..\Headers\OptionsScene.h"

// Constructor
OptionsScene::OptionsScene(Game* game_) : MenuScene(game_) {
	createTitleText();
	createMenuText();
}

void OptionsScene::returnToPreviousScene() {
	game->popScene();
	MenuScene::mustBreak = true;
}

void OptionsScene::createTitleText() {
	float title_offset = 108.0f;
	int fontSize = 72;
	sf::Color fontColor = sf::Color::Color(165, 25, 100, 255);

	game->textManager.createText("optionsTitle", "title", fontSize, fontColor, "OPTIONS", game->config->screenWidth / 2, (game->config->screenHeight / 4) - (title_offset / 2));
	std::string optionsTitle = "optionsTitle";
	titleTextRefsVec.push_back(optionsTitle);
}

void OptionsScene::createMenuText() {
	float text_offset = 54.0f;
	int fontSize = 36;
	sf::Color fontColor = sf::Color::Color(165, 25, 100, 255);

	game->textManager.createText("volumeOptions", "standard", fontSize, selectedFontColor, "VOLUME", game->config->screenWidth / 2, game->config->screenHeight / 2);
	std::string volumeOptions = "volumeOptions";
	menuTextRefsVec.push_back(volumeOptions);

	game->textManager.createText("returnOptions", "standard", fontSize, unselectedFontColor, "RETURN", game->config->screenWidth / 2, (game->textManager.getTextRef(volumeOptions).getPosition().y + text_offset));
	std::string returnOptions = "returnOptions";
	menuTextRefsVec.push_back(returnOptions);
}

void OptionsScene::selectMenuItem() {
	switch (selectedTextIndex) {
		case 0:
			// allow volume change
			break;
		case 1:
			// move to main menu scene
			returnToPreviousScene();
			break;
	}
}