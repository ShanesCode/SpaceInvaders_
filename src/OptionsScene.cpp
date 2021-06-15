#include "../Headers/OptionsScene.h"

// Constructor
OptionsScene::OptionsScene(Game* game_) : MenuScene(game_) {
	createTitleText();
	createMenuText();

	max_volume = 100.0f;
	min_volume = 0.0f;

	initSliderGraphics();
}

void OptionsScene::draw(const float dt) {
	game->window.setView(view);

	game->window.clear(sf::Color::Black);
	//game->window.draw(game->background);
	drawTitleText();
	drawMenuText();
	game->window.draw(sliderBG);
	game->window.draw(slider);
}

void OptionsScene::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed: {
			game->quit();
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
	float prev_volume = game->config->volume;
	float volume_increment = 5.0f;
	float new_volume;

	if (increase) {
		new_volume = prev_volume + volume_increment;
		// Prevent going over max volume
		if (new_volume <= max_volume) {
			// Update the config file so that the setting is saved
			game->config->updateConfig("volume", new_volume);
			// Change volume in audioManager
			game->audioManager.changeVolume(new_volume);
		}
	}
	else {
		new_volume = prev_volume - volume_increment;
		// Prevent going over max volume
		if (new_volume >= min_volume) {
			// Update the config file so that the setting is saved
			game->config->updateConfig("volume", new_volume);
			// Change volume in audioManager
			game->audioManager.changeVolume(new_volume);
		}
	}

	updateSliderGraphic();
}

void OptionsScene::initSliderGraphics() {
	// Bar behind slider
	sliderBG.setTexture(game->textureManager.getRef("sliderBG"));
	sliderBG.setScale(sf::Vector2f(2.0f, 2.0f));
	// X position
	int sliderBG_xpos = game->textManager.getTextRef("volumeOptions").getPosition().x - sliderBG.getGlobalBounds().width / 2;
	// Y position
	int ypos_offset = 40;
	int sliderBG_ypos = game->textManager.getTextRef("volumeOptions").getPosition().y - ypos_offset;
	sliderBG.setPosition(sf::Vector2f(sliderBG_xpos, sliderBG_ypos));
	float sliderBG_width = sliderBG.getGlobalBounds().width;
	float hundredth = sliderBG_width / 100;

	// Slider knob
	slider.setTexture(game->textureManager.getRef("slider"));
	slider.setScale(sf::Vector2f(2.0f, 2.0f));
	// X position should be equivalent to the current volume percentage, within the bounds of the sliderBG. Subtract half of width due to top-left origin
	int slider_xpos = sliderBG.getPosition().x - slider.getGlobalBounds().width / 2 + hundredth * game->config->volume;
	// Y position should be the position of the sliderBG, plus half sliderBG height and minus half the height of the slider due to top-left origin
	int slider_ypos = sliderBG.getPosition().y + sliderBG.getGlobalBounds().height / 2 - slider.getGlobalBounds().height / 2;
	slider.setPosition(sf::Vector2f(slider_xpos, slider_ypos));
}

void OptionsScene::updateSliderGraphic() {
	float sliderBG_width = sliderBG.getGlobalBounds().width;
	float hundredth = sliderBG_width / 100;

	// X position should be equivalent to the current volume percentage, within the bounds of the sliderBG. Subtract half of width due to top-left origin
	int slider_xpos = sliderBG.getPosition().x - slider.getGlobalBounds().width / 2 + hundredth * game->config->volume;

	slider.setPosition(sf::Vector2f(slider_xpos, slider.getPosition().y));
}