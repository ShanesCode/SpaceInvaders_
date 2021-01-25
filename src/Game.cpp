#include <stack>
#include <SFML/System.hpp>

#include "../Headers/Game.h"
#include "../Headers/Scene.h"


void Game::pushScene(Scene* scene) {
	this->scenes.push(scene);
}

void Game::popScene() {
	delete this->scenes.top();
	this->scenes.pop();
}

void Game::changeScene(Scene* scene) {
	if (!this->scenes.empty()) {
		popScene();
	}
	else {
		pushScene(scene);
	}
}

Scene* Game::peekScene() {
	if (this->scenes.empty()) {
		return nullptr;
	}
	else {
		return this->scenes.top();
	}
}

void Game::gameLoop() {
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekScene() == nullptr) continue;
		peekScene()->handleInput();
		peekScene()->update(dt);
		this->window.clear(sf::Color::Black);
		peekScene()->draw(dt);
		this->window.display();
	}
}

Game::Game(Config& config) {
	this->loadTextures();

	this->window.create(sf::VideoMode(config.screenWidth, config.screenHeight), "Space Invaders_");
	this->window.setFramerateLimit(60);

	this->background.setTexture(this->textureManager.getRef("background"));
}

Game::~Game() {
	while (!this->scenes.empty()) {
		popScene();
	}
}

void Game::loadTextures() {
	textureManager.loadTexture("background", "Resource/Space_Invaders_flyer,_1978.jpg");
}