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
	bool must_break = false;
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
				game->popScene();
				must_break = true;
			}
		}
		}
		if (must_break) { break; }
	}
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
	float title_offset = 108.0f;
	int fontSize = 72;
	sf::Color fontColor = sf::Color::Color(165, 25, 100, 255);
}

void OptionsScene::drawMenuText() {
	for (int i = 0; i < menuTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(menuTextRefsVec[i]));
	}
}