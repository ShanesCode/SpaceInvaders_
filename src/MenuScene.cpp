#include "../Headers/MenuScene.h"

// Constructor
MenuScene::MenuScene(Game* game_) {
	game = game_;
	pos = sf::Vector2f(game->window.getSize());
	view.setSize(pos);
	pos *= 0.5f;
	view.setCenter(pos);

	unselectedFontColor = sf::Color::White;
	selectedFontColor = sf::Color::Green;

	selectedTextIndex = 0;

	mustBreak = false;
}

void MenuScene::draw(const float dt) {
	game->window.setView(view);

	game->window.clear(sf::Color::Black);
	//game->window.draw(game->background);
	drawTitleText();
	drawMenuText();
}

void MenuScene::update(const float dt) {

}

void MenuScene::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed: {
			game->quit();
			break;
		}
		case sf::Event::Resized: {
			view.setSize(event.size.width, event.size.height);
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
		// Check for mustBreak, goes to true when a scene is destroyed to prevent accessing deallocated memory
		if (mustBreak) { break; }
	}
}

void MenuScene::createTitleText() {}

void MenuScene::drawTitleText() {
	for (int i = 0; i < titleTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(titleTextRefsVec[i]));
	}
}

void MenuScene::createMenuText() {}

void MenuScene::drawMenuText() {
	for (int i = 0; i < menuTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(menuTextRefsVec[i]));
	}
}

void MenuScene::navigateMenu(bool downwards) {
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

void MenuScene::selectMenuItem() {}