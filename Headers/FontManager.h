#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class FontManager {
private:
	// Map of fonts
	std::map<std::string, sf::Font> fonts;

public:
	// Add a font from a file
	void loadFont(const std::string& name, const std::string& filename);

	// Translate an id into a reference
	sf::Font& getFontRef(const std::string& text);
};