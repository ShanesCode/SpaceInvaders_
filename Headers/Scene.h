#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <algorithm>
#include "Config.h"

class Scene {
	public:
		std::string sceneName;

		sf::Text createText(const sf::Font& font, int size, sf::Color color, std::string string, float xpos, float ypos);
		void updateText(int textVectorIndex, const sf::Font& font, int size, sf::Color color, std::string string, float xpos, float ypos);

		std::vector<sf::Text> textVector;

		virtual void createTextElements(Config& config);

		sf::Music music;
		std::string musicString;

		virtual void playMusic(bool loop, float volume);
		
		Scene(std::string sceneName_, std::string musicString_, Config& config);
};