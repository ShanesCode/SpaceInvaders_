#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include "Config.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "TextManager.h"

class Scene;

class Game {
	private:
		void loadTextures();
		void loadSounds();
		void loadFonts();

	public:
		std::stack<Scene*> scenes;

		sf::RenderWindow window;
		sf::Sprite background;

		AudioManager audioManager;
		TextureManager textureManager;
		FontManager fontManager;
		TextManager textManager;

		void pushScene(Scene* scene);
		void popScene();
		void changeScene(Scene* scene);
		Scene* peekScene();

		void gameLoop();

		Game(Config& config);

		~Game();
};