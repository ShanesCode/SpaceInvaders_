#include "..\Headers\FontManager.h"

void FontManager::loadFont(const std::string& name, const std::string& filename) {
	// Load the texture
	sf::Font font;
	font.loadFromFile(filename);

	fonts[name] = font;
}

sf::Font& FontManager::getFontRef(const std::string& font) {
	return fonts.at(font);
}

