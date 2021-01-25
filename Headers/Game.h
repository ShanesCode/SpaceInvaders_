#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include "Config.h"
#include "TextureManager.h"

class Scene;

class Game {
	private:
		void loadTextures();

	public:
		std::stack<Scene*> scenes;

		sf::RenderWindow window;
		TextureManager textureManager;
		sf::Sprite background;

		void pushScene(Scene* scene);
		void popScene();
		void changeScene(Scene* scene);
		Scene* peekScene();

		void gameLoop();

		Game(Config& config);

		~Game();
};