#include "..\Headers\MainMenuScene.h"

// Constructor
MainMenuScene::MainMenuScene(Game* game_) : menuIndex(0) 
{
	game = game_;
	sf::Vector2f pos = sf::Vector2f(game->window.getSize());
	view.setSize(pos);
	pos *= 0.5f;
	view.setCenter(pos);
	std::cout << "MainMenu" << std::endl;

	createTitleText();
	createMenuText();

	selectedTextIndex = menuIndex;
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
				
				game->background.setPosition(game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
				game->background.setScale(
					float(event.size.width / float(game->background.getTexture()->getSize().x)),
					float(event.size.height) / float(game->background.getTexture()->getSize().y)
				);
				break;
			}
			case sf::Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::Escape) {
					game->window.close();
				}
				else if (event.key.code == sf::Keyboard::Space) {
					loadGame();
				}
			}
			default: break;
		}
	}
}

void MainMenuScene::loadGame() {
	game->pushScene(new GameScene(game));
	std::cout << "Game" << std::endl;
}

void MainMenuScene::createTitleText() {
	float title_offset = 108.0f;
	float shadow_offset = 10.0f;
	int fontSize = 108;
	sf::Color fontColor2 = sf::Color::Color(254, 51, 47, 150);
	sf::Color fontColor1 = sf::Color::Color(248, 88, 66, 200);
	sf::Color fontColor = sf::Color::Yellow;

	game->textManager.createText("spaceTextShadow2", "title", fontSize, fontColor2, "SPACE", game->config->screenWidth / 2, (game->config->screenHeight / 4) - (title_offset / 2));
	sf::Text* spaceTextShadow2 = &(game->textManager.getTextRef("spaceTextShadow2"));
	titleTextVec.push_back(spaceTextShadow2);

	game->textManager.createText("invadersTextShadow2", "title", fontSize, fontColor2, "INVADERS", game->config->screenWidth / 2, (game->config->screenHeight / 4) + (title_offset / 2));
	sf::Text* invadersTextShadow2 = &(game->textManager.getTextRef("invadersTextShadow2"));
	titleTextVec.push_back(invadersTextShadow2);
	
	game->textManager.createText("spaceTextShadow1", "title", fontSize, fontColor1, "SPACE", spaceTextShadow2->getPosition().x, spaceTextShadow2->getPosition().y + shadow_offset);
	sf::Text* spaceTextShadow1 = &(game->textManager.getTextRef("spaceTextShadow1"));
	titleTextVec.push_back(spaceTextShadow1);
	
	game->textManager.createText("invadersTextShadow1", "title", fontSize, fontColor1, "INVADERS", invadersTextShadow2->getPosition().x, invadersTextShadow2->getPosition().y + shadow_offset);
	sf::Text* invadersTextShadow1 = &(game->textManager.getTextRef("invadersTextShadow1"));
	titleTextVec.push_back(invadersTextShadow1);
	
	game->textManager.createText("spaceText", "title", fontSize, fontColor, "SPACE", spaceTextShadow1->getPosition().x, spaceTextShadow1->getPosition().y + shadow_offset);
	sf::Text* spaceText = &(game->textManager.getTextRef("spaceText"));
	titleTextVec.push_back(spaceText);
	
	game->textManager.createText("invadersText", "title", fontSize, fontColor, "INVADERS", invadersTextShadow1->getPosition().x, invadersTextShadow1->getPosition().y + shadow_offset);
	sf::Text* invadersText = &(game->textManager.getTextRef("invadersText"));
	titleTextVec.push_back(invadersText);
}

void MainMenuScene::drawTitleText() {
	for (int i = 0; i < titleTextVec.size(); i++) {
		game->window.draw(*titleTextVec[i]);
	}
}

void MainMenuScene::createMenuText() {
	float text_offset = 54.0f;
	int fontSize = 36;
	sf::Color fontColor = sf::Color::White;

	//	float menu_text_offset = 54.0f;

	game->textManager.createText("startText", "standard", fontSize, fontColor, "START", game->config->screenWidth / 2, game->config->screenHeight / 2);
	sf::Text* startText = &(game->textManager.getTextRef("startText"));
	menuTextVec.push_back(startText);

	game->textManager.createText("hiscoresText", "standard", fontSize, fontColor, "HISCORES", game->config->screenWidth / 2, (startText->getPosition().y + text_offset));
	sf::Text* hiscoresText = &(game->textManager.getTextRef("hiscoresText"));
	menuTextVec.push_back(hiscoresText);

	game->textManager.createText("optionsText", "standard", fontSize, fontColor, "OPTIONS", game->config->screenWidth / 2, (hiscoresText->getPosition().y + text_offset));
	sf::Text* optionsText = &(game->textManager.getTextRef("optionsText"));
	menuTextVec.push_back(optionsText);

	game->textManager.createText("quitText", "standard", fontSize, fontColor, "QUIT", game->config->screenWidth / 2, (optionsText->getPosition().y + text_offset));
	sf::Text* quitText = &(game->textManager.getTextRef("quitText"));
	menuTextVec.push_back(quitText);
}

void MainMenuScene::drawMenuText() {
	for (int i = 0; i < menuTextVec.size(); i++) {
		game->window.draw(*menuTextVec[i]);
	}
}

//void MainMenuScene::navigateMenu(bool downwards) {
//	// Set currently selected text to white
//	game->textManager.updateTextColor(textRefName, sf::Color::White);
//	
//	if (downwards) {
//	// Navigate downwards
//		if (selectedTextIndex == menuIndex) {
//			// Prevent out of vector
//			selectedTextIndex = textVector.size() - 1;
//		}
//		else {
//			selectedTextIndex--;
//		}
//	}
//	else {
//	// Navigate upwards
//		if (selectedTextIndex == textVector.size() - 1) {
//			// Prevent out of vector
//			selectedTextIndex = menuIndex;
//		}
//		else {
//			selectedTextIndex++;
//		}
//	}
//	// Set new selected text to green
//	game->textManager.updateTextColor(textRefName, sf::Color::White);
//}