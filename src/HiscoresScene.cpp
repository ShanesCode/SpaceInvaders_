#include "..\Headers\HiscoresScene.h"

// Constructor
HiscoresScene::HiscoresScene(Game* game_) {
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

void HiscoresScene::draw(const float dt) {
	game->window.setView(view);

	game->window.clear(sf::Color::Black);
	//game->window.draw(game->background);
	drawTitleText();
	drawMenuText();
}

void HiscoresScene::update(const float dt) {

}

void HiscoresScene::handleInput() {
	bool mustBreak = false;
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
				if (event.key.code == sf::Keyboard::Escape) {
					game->popScene();
					mustBreak = true;
				}
			}
		}
		if (mustBreak) { break; }
	}
}

void HiscoresScene::createTitleText() {
	float title_offset = 108.0f;
	int fontSize = 72;
	sf::Color fontColor = sf::Color::Color(165, 25, 100, 255);

	game->textManager.createText("hiscoresTitle", "title", fontSize, fontColor, "HISCORES", game->config->screenWidth / 2, (game->config->screenHeight / 4) - (title_offset / 2));
	std::string hiscoresTitle = "hiscoresTitle";
	titleTextRefsVec.push_back(hiscoresTitle);
}

void HiscoresScene::drawTitleText() {
	for (int i = 0; i < titleTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(titleTextRefsVec[i]));
	}
}

void HiscoresScene::createMenuText() {
	float title_offset = 108.0f;
	int fontSize = 72;
	sf::Color fontColor = sf::Color::Color(165, 25, 100, 255);
}

void HiscoresScene::drawMenuText() {
	for (int i = 0; i < menuTextRefsVec.size(); i++) {
		game->window.draw(game->textManager.getTextRef(menuTextRefsVec[i]));
	}
}