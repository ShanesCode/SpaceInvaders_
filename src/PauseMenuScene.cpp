#include "..\Headers\PauseMenuScene.h"

// Constructor
PauseMenuScene::PauseMenuScene(Game* game_) {
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

	must_break = false;
}

void PauseMenuScene::draw(const float dt) {
	game->window.setView(view);

	game->window.clear(sf::Color::Black);
	//game->window.draw(game->background);
	drawTitleText();
	drawMenuText();
}

void PauseMenuScene::update(const float dt) {

}

void PauseMenuScene::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed: {
				game->window.close();
				break;
			}
			case sf::Event::Resized: {
				view.setSize(event.size.width, event.size.height);
				break;
			}
			case sf::Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::Escape) {
					returnToPreviousScene();
				}
				else if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Enter) {
					selectMenuItem();
				}
				else if (event.key.code == sf::Keyboard::Down) {
					navigateMenu(true);
				}
				else if (event.key.code == sf::Keyboard::Up) {
					navigateMenu(false);
				}
			}
		}
		if (must_break) { break; }
	}
}

void PauseMenuScene::returnToPreviousScene() {
	game->popScene();
	must_break = true;
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

void PauseMenuScene::drawTitleText() {
	for (int i = 0; i < titleTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(titleTextRefsVec[i]));
	}
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

	game->textManager.createText("menuPause", "standard", fontSize, unselectedFontColor, "MAIN MENU", game->config->screenWidth / 2, (game->textManager.getTextRef(optionsPause).getPosition().y + text_offset));
	std::string menuPause = "menuPause";
	menuTextRefsVec.push_back(menuPause);

	game->textManager.createText("quitPause", "standard", fontSize, unselectedFontColor, "QUIT", game->config->screenWidth / 2, (game->textManager.getTextRef(menuPause).getPosition().y + text_offset));
	std::string quitPause = "quitPause";
	menuTextRefsVec.push_back(quitPause);
}

void PauseMenuScene::drawMenuText() {
	for (int i = 0; i < menuTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(menuTextRefsVec[i]));
	}
}

void PauseMenuScene::navigateMenu(bool downwards) {
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

void PauseMenuScene::selectMenuItem() {
	switch (selectedTextIndex) {
		case 0:
			// return to game
			returnToPreviousScene();
			break;
		case 1:
			// move to options scene
			returnToPreviousScene();
			break;
		case 2:
			// move to main menu scene
			goToOptionsScene();
			break;
		case 3:
			// quit game
			game->window.close();
			break;
	}
}