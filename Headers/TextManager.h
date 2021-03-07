#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextManager {
private:
	// Array of texts, fonts
	std::map<std::string, sf::Text> texts;
	std::map<std::string, sf::Font> fonts;

public:
	// Add a font from a file
	void loadFont(const std::string& name, const std::string& filename);

	void createText(const std::string& name, const std::string& fontName, int size, sf::Color color, std::string string, float xpos, float ypos);
	void updateText(const std::string& textName, const std::string& fontName, int size, sf::Color color, std::string string, float xpos, float ypos);

	// Translate an id into a reference
	sf::Text& getTextRef(const std::string& text);
	sf::Font& getFontRef(const std::string& text);

	TextManager() {
	}
};