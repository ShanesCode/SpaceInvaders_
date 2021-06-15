#include "../Headers/TextManager.h"

TextManager::TextManager(FontManager* fontManager_) {
	fontManager = fontManager_;
}

void TextManager::createText(const std::string& name, const std::string& fontName, int size, sf::Color color, std::string string, float xpos, float ypos) {
	sf::Text text;
	sf::Font* font = &fontManager->getFontRef(fontName);

	text.setFont(*font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setString(string);
	text.setOrigin(text.getGlobalBounds().left + text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().top + text.getGlobalBounds().height / 2.0f);
	text.setPosition(xpos, ypos);

	texts[name] = text;
}

void TextManager::updateTextString(const std::string& textName, std::string string) {
	sf::Text text = getTextRef(textName);
	text.setString(string);
	texts[textName] = text;
}

void TextManager::updateTextColor(const std::string& textName, sf::Color color) {
	sf::Text text = getTextRef(textName);
	text.setFillColor(color);
	texts[textName] = text;
}

void TextManager::updateTextSize(const std::string& textName, int size) {
	sf::Text text = getTextRef(textName);
	text.setCharacterSize(size);
	texts[textName] = text;
}

void TextManager::updateTextPosition(const std::string& textName, float xpos, float ypos) {
	sf::Text text = getTextRef(textName);
	text.setPosition(xpos, ypos);
	texts[textName] = text;
}

void TextManager::updateTextFont(const std::string& textName, const std::string& fontName) {
	sf::Text text = getTextRef(textName);
	sf::Font font = fontManager->getFontRef(fontName);
	text.setFont(font);
	texts[textName] = text;
}


sf::Text& TextManager::getTextRef(const std::string& text) {
	return texts.at(text);
}

