#include "..\Headers\OptionsScene.h"

// Constructor
OptionsScene::OptionsScene(Game* game_) : MenuScene(game_) {
	createTitleText();
	createMenuText();
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
			
			if (selectedTextIndex == 0) {
				if (event.key.code == sf::Keyboard::Left) {
					changeVolumeSlider(false);
				}
				else if (event.key.code == sf::Keyboard::Right) {
					changeVolumeSlider(true);
				}
			}
		}
		default: break;
		}
		// Check for mustBreak, goes to true when a scene is destroyed to prevent accessing deallocated memory
		if (mustBreak) { break; }
	}
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

void OptionsScene::changeVolumeSlider(bool increase) {
	float volume_increment = 5.0f;

	if (increase) {
		game->config->volume + volume_increment;
	}
	else {
		game->config->volume - volume_increment;
	}
}