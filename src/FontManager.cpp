#include "..\Headers\FontManager.h"

void FontManager::loadFont(const std::string& name, const std::string& filename) {
	// Load the texture
	sf::Font font;
	if (!font.loadFromFile(filename))
	{
		std::cout << "There was an error loading the font: " << filename;
	}

	fonts[name] = font;
}

sf::Font& FontManager::getFontRef(const std::string& font) {
	return fonts.at(font);
}

