#include "..\Headers\OptionsScene.h"

// Constructor
OptionsScene::OptionsScene(Game* game_) {
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

void OptionsScene::draw(const float dt) {
	game->window.setView(view);

	game->window.clear(sf::Color::Black);
	//game->window.draw(game->background);
	drawTitleText();
	drawMenuText();
}

void OptionsScene::update(const float dt) {

}

void OptionsScene::handleInput() {
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

void OptionsScene::returnToPreviousScene() {
	game->popScene();
	must_break = true;
}

void OptionsScene::createTitleText() {
	float title_offset = 108.0f;
	int fontSize = 72;
	sf::Color fontColor = sf::Color::Color(165, 25, 100, 255);

	game->textManager.createText("optionsTitle", "title", fontSize, fontColor, "OPTIONS", game->config->screenWidth / 2, (game->config->screenHeight / 4) - (title_offset / 2));
	std::string optionsTitle = "optionsTitle";
	titleTextRefsVec.push_back(optionsTitle);
}

void OptionsScene::drawTitleText() {
	for (int i = 0; i < titleTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(titleTextRefsVec[i]));
	}
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

void OptionsScene::drawMenuText() {
	for (int i = 0; i < menuTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(menuTextRefsVec[i]));
	}
}

void OptionsScene::navigateMenu(bool downwards) {
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