#include "../Headers/Scenes/MainMenuScene.h"
#include "../Headers/Scenes/GameScene.h"

void MainMenuScene::draw(const float dt) {
	this->game->window.setView(this->view);

	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->background);
}

void MainMenuScene::update(const float dt) {

}

void MainMenuScene::handleInput() {
	sf::Event event;

	while (this->game->window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed: {
				game->window.close();
				break;
			}
			case sf::Event::Resized: {
				this->view.setSize(event.size.width, event.size.height);
				
				this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
				this->game->background.setScale(
					float(event.size.width / float(this->game->background.getTexture()->getSize().x)),
					float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
				break;
			}
			case sf::Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::Escape) {
					this->game->window.close();
				}
			}
			default: break;
		}
	}
}

MainMenuScene::MainMenuScene(Game* game) {
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);
}

void MainMenuScene::loadGame() {
	this->game->pushScene(new GameScene(this->game));
}