#include "../Headers/Game.h"
#include "../Headers/Scene.h"

// Constructor
Game::Game(Config* config_) : textManager(&fontManager) {
	config = config_;
	loadTextures();
	loadSoundBuffers();
	loadFonts();

	window.create(sf::VideoMode(config->screenWidth, config->screenHeight), "Space Invaders_");
	window.setFramerateLimit(120);

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
	// Misc
	textureManager.loadTexture("background", "Resource/Space_Invaders_flyer,_1978.jpg");
	
	// Gameplay
	textureManager.loadTexture("alien0", "Resource/alien0.png");
	textureManager.loadTexture("alien1", "Resource/alien1.png");
	textureManager.loadTexture("alien2", "Resource/alien2.png");
	textureManager.loadTexture("alien_death", "Resource/alien_death.png");
	textureManager.loadTexture("player", "Resource/player.png");
	textureManager.loadTexture("bullet", "Resource/bullet.png");
	textureManager.loadTexture("bullet_miss", "Resource/bullet_miss.png");
	textureManager.loadTexture("saucer", "Resource/saucer.png", sf::IntRect(0, 0, 16, 16));
	textureManager.loadTexture("saucer_death", "Resource/saucer.png", sf::IntRect(16, 0, 16, 16));

	// UI
	textureManager.loadTexture("sliderBG", "Resource/sliderBG.png");
	textureManager.loadTexture("slider", "Resource/slider.png");
}

void Game::loadSoundBuffers() {
	audioManager.loadSoundBuffer("fire", "Resource/fire.wav");
	audioManager.loadSoundBuffer("saucer_move", "Resource/saucer_move.wav");
	audioManager.loadSoundBuffer("saucer_death", "Resource/saucer_death.wav");
}

void Game::loadFonts() {
	fontManager.loadFont("title", "Resource/MachineStd-Bold.otf");
	fontManager.loadFont("standard", "Resource/space_invaders.ttf");
}

void Game::quit() {
	config->updateConfigFile();
	window.close();
}