#include "..\Headers\MainMenuScene.h"

// Constructor
MainMenuScene::MainMenuScene(Game* game_) {
	game = game_;
	sf::Vector2f pos = sf::Vector2f(game->window.getSize());
	view.setSize(pos);
	pos *= 0.5f;
	view.setCenter(pos);

	unselectedFontColor = sf::Color::White;
	selectedFontColor = sf::Color::Green;

	createTitleText();
	createMenuText();

	selectedTextIndex = 0;
}

void MainMenuScene::draw(const float dt) {
	game->window.setView(view);

	game->window.clear(sf::Color::Black);
	//game->window.draw(game->background);
	drawTitleText();
	drawMenuText();
}

void MainMenuScene::update(const float dt) {

}

void MainMenuScene::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed: {
				game->window.close();
				break;
			}
			case sf::Event::Resized: {
				view.setSize(event.size.width, event.size.height);
				
				/*game->background.setPosition(game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
				game->background.setScale(
					float(event.size.width / float(game->background.getTexture()->getSize().x)),
					float(event.size.height) / float(game->background.getTexture()->getSize().y)
				);*/
				break;
			}
			case sf::Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Enter) {
					selectMenuItem();
				}
				else if (event.key.code == sf::Keyboard::Down) {
					navigateMenu(true);
				}
				else if (event.key.code == sf::Keyboard::Up) {
					navigateMenu(false);
				}
			}
			default: break;
		}
	}
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

void MainMenuScene::drawTitleText() {
	for (int i = 0; i < titleTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(titleTextRefsVec[i]));
	}
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

void MainMenuScene::drawMenuText() {
	for (int i = 0; i < menuTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(menuTextRefsVec[i]));
	}
}

void MainMenuScene::navigateMenu(bool downwards) {
	// Set currently selected text to white
	game->textManager.updateTextColor(menuTextRefsVec[selectedTextIndex], unselectedFontColor);
	
	if (!downwards) {
	// Navigate downwards
		selectedTextIndex = (selectedTextIndex - 1) % menuTextRefsVec.size();
	}
	else {
	// Navigate upwards
		selectedTextIndex = (selectedTextIndex + 1) % menuTextRefsVec.size();
	}
	// Set new selected text to green
	game->textManager.updateTextColor(menuTextRefsVec[selectedTextIndex], selectedFontColor);
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