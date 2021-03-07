#include "..\Headers\TextManager.h"

void TextManager::createText(const std::string& name, const std::string& fontName, int size, sf::Color color, std::string string, float xpos, float ypos) {
	sf::Text text;
	sf::Font font = getFontRef(fontName);

	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setString(string);
	text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
	text.setPosition(xpos, ypos);

	texts[name] = text;
}

void TextManager::updateText(const std::string& textName, const std::string& fontName, int size, sf::Color color, std::string string, float xpos, float ypos) {
	sf::Text text = getTextRef(textName);
	sf::Font font = getFontRef(fontName);
	
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setString(string);
	text.setPosition(xpos, ypos);
}

sf::Text& TextManager::getTextRef(const std::string& text) {
	return texts.at(text);
}

void TextManager::loadFont(const std::string& name, const std::string& filename) {
	// Load the texture
	sf::Font font;
	font.loadFromFile(filename);

	fonts[name] = font;
}

sf::Font& TextManager::getFontRef(const std::string& font) {
	return fonts.at(font);
}

