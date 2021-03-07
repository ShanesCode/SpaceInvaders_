#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "FontManager.h"

class TextManager {
private:
	// Map of texts
	std::map<std::string, sf::Text> texts;

	FontManager fontManager;

public:
	void createText(const std::string& name, const std::string& fontName, int size, sf::Color color, std::string string, float xpos, float ypos);
	void updateText(const std::string& textName, const std::string& fontName, int size, sf::Color color, std::string string, float xpos, float ypos);

	// Translate an id into a reference
	sf::Text& getTextRef(const std::string& text);
};