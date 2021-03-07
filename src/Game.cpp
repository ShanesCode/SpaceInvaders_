#include "..\Headers\Game.h"
#include "..\Headers\Scene.h"

// Constructor
Game::Game(Config& config) {
	loadTextures();

	window.create(sf::VideoMode(config.screenWidth, config.screenHeight), "Space Invaders_");
	window.setFramerateLimit(60);

	background.setTexture(textureManager.getRef("background"));
}

// Destructor
Game::~Game() {
	while (!scenes.empty()) {
		popScene();
	}
}

// Public Functions
void Game::pushScene(Scene* scene) {
	scenes.push(scene);
}

void Game::popScene() {
	delete scenes.top();
	scenes.pop();
}

void Game::changeScene(Scene* scene) {
	if (!scenes.empty()) {
		popScene();
	}
	else {
		pushScene(scene);
	}
}

Scene* Game::peekScene() {
	if (scenes.empty()) {
		return nullptr;
	}
	else {
		return scenes.top();
	}
}

void Game::gameLoop() {
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekScene() == nullptr) continue;
		peekScene()->handleInput();
		peekScene()->update(dt);
		window.clear(sf::Color::Black);
		peekScene()->draw(dt);
		window.display();
	}
}

void Game::loadTextures() {
	textureManager.loadTexture("background", "Resource/Space_Invaders_flyer,_1978.jpg");
}

void Game::loadSounds() {
	// audioManager.loadSound("background", "Resource/Space_Invaders_flyer,_1978.jpg");
}

void Game::loadFonts() {
	fontManager.loadFont("title", "Resource/MachineStd-Bold.otf");
	fontManager.loadFont("standard", "Resource/space_invaders.ttf");
}