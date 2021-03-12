#include "..\Headers\MainMenuScene.h"

// Constructor
MainMenuScene::MainMenuScene(Game* game_) : MenuScene(game_) {
	createTitleText();
	createMenuText();
	playMenuMusic();
}

void MainMenuScene::goToGameScene() {
	game->pushScene(new GameScene(game));
}

void MainMenuScene::goToHiscoresScene() {
	game->pushScene(new HiscoresScene(game));
}

void MainMenuScene::goToOptionsScene() {
	game->pushScene(new OptionsScene(game));
}

void MainMenuScene::createTitleText() {
	float title_offset = 108.0f;
	float shadow_offset = 10.0f;
	int fontSize = 108;
	sf::Color fontColor2 = sf::Color::Color(254, 51, 47, 150);
	sf::Color fontColor1 = sf::Color::Color(248, 88, 66, 200);
	sf::Color fontColor = sf::Color::Yellow;

	game->textManager.createText("spaceTextShadow2MainMenu", "title", fontSize, fontColor2, "SPACE", game->config->screenWidth / 2, (game->config->screenHeight / 4) - (title_offset / 2));
	std::string spaceTextShadow2MainMenu = "spaceTextShadow2MainMenu";
	titleTextRefsVec.push_back(spaceTextShadow2MainMenu);

	game->textManager.createText("invadersTextShadow2MainMenu", "title", fontSize, fontColor2, "INVADERS", game->config->screenWidth / 2, (game->config->screenHeight / 4) + (title_offset / 2));
	std::string invadersTextShadow2MainMenu = "invadersTextShadow2MainMenu";
	titleTextRefsVec.push_back(invadersTextShadow2MainMenu);
	
	game->textManager.createText("spaceTextShadow1MainMenu", "title", fontSize, fontColor1, "SPACE", game->textManager.getTextRef(spaceTextShadow2MainMenu).getPosition().x, (game->textManager.getTextRef(spaceTextShadow2MainMenu).getPosition().y + shadow_offset));
	std::string spaceTextShadow1MainMenu = "spaceTextShadow1MainMenu";
	titleTextRefsVec.push_back(spaceTextShadow1MainMenu);
	
	game->textManager.createText("invadersTextShadow1MainMenu", "title", fontSize, fontColor1, "INVADERS", game->textManager.getTextRef(invadersTextShadow2MainMenu).getPosition().x, (game->textManager.getTextRef(invadersTextShadow2MainMenu).getPosition().y + shadow_offset));
	std::string invadersTextShadow1MainMenu = "invadersTextShadow1MainMenu";
	titleTextRefsVec.push_back(invadersTextShadow1MainMenu);
	
	game->textManager.createText("spaceTextMainMenu", "title", fontSize, fontColor, "SPACE", game->textManager.getTextRef(spaceTextShadow1MainMenu).getPosition().x, (game->textManager.getTextRef(spaceTextShadow1MainMenu).getPosition().y + shadow_offset));
	std::string spaceTextMainMenu = "spaceTextMainMenu";
	titleTextRefsVec.push_back(spaceTextMainMenu);
	
	game->textManager.createText("invadersTextMainMenu", "title", fontSize, fontColor, "INVADERS", game->textManager.getTextRef(invadersTextShadow1MainMenu).getPosition().x, (game->textManager.getTextRef(invadersTextShadow1MainMenu).getPosition().y + shadow_offset));
	std::string invadersTextMainMenu = "invadersTextMainMenu";
	titleTextRefsVec.push_back(invadersTextMainMenu);
}

void MainMenuScene::createMenuText() {
	float text_offset = 54.0f;
	int fontSize = 36;

	game->textManager.createText("startMainMenu", "standard", fontSize, selectedFontColor, "START", game->config->screenWidth / 2, game->config->screenHeight / 2);
	std::string startMainMenu = "startMainMenu";
	menuTextRefsVec.push_back(startMainMenu);

	game->textManager.createText("hiscoresMainMenu", "standard", fontSize, unselectedFontColor, "HISCORES", game->config->screenWidth / 2, (game->textManager.getTextRef(startMainMenu).getPosition().y + text_offset));
	std::string hiscoresMainMenu = "hiscoresMainMenu";
	menuTextRefsVec.push_back(hiscoresMainMenu);

	game->textManager.createText("optionsMainMenu", "standard", fontSize, unselectedFontColor, "OPTIONS", game->config->screenWidth / 2, (game->textManager.getTextRef(hiscoresMainMenu).getPosition().y + text_offset));
	std::string optionsMainMenu = "optionsMainMenu";
	menuTextRefsVec.push_back(optionsMainMenu);

	game->textManager.createText("quitMainMenu", "standard", fontSize, unselectedFontColor, "QUIT", game->config->screenWidth / 2, (game->textManager.getTextRef(optionsMainMenu).getPosition().y + text_offset));
	std::string quitMainMenu = "quitMainMenu";
	menuTextRefsVec.push_back(quitMainMenu);
}

void MainMenuScene::selectMenuItem() {
	switch (selectedTextIndex) {
		case 0:
			// move to game scene
			goToGameScene();
			break;
		case 1:
			// move to hiscores scene
			goToHiscoresScene();
			break;
		case 2:
			// move to options scene
			goToOptionsScene();
			break;
		case 3:
			// quit game
			game->window.close();
			break;
		}
}

void MainMenuScene::playMenuMusic() {
	game->audioManager.stopMusic();
	game->audioManager.playMusic(true, game->config->volume, "Resource/JoeReMi Music - Title Screen Theme (chiptune).ogg");
}