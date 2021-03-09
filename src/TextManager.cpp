#include "..\Headers\TextManager.h"

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
	text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
	text.setPosition(xpos, ypos);

	texts[name] = text;
}

void TextManager::updateTextString(const std::string& textName, std::string string) {
	sf::Text text = getTextRef(textName);
	text.setString(string);
}

void TextManager::updateTextColor(const std::string& textName, sf::Color color) {
	sf::Text text = getTextRef(textName);
	text.setFillColor(color);
}

void TextManager::updateTextSize(const std::string& textName, int size) {
	sf::Text text = getTextRef(textName);
	text.setCharacterSize(size);
}

void TextManager::updateTextPosition(const std::string& textName, float xpos, float ypos) {
	sf::Text text = getTextRef(textName);
	text.setPosition(xpos, ypos);
}

void TextManager::updateTextFont(const std::string& textName, const std::string& fontName) {
	sf::Text text = getTextRef(textName);
	sf::Font font = fontManager->getFontRef(fontName);
	text.setFont(font);
}


sf::Text& TextManager::getTextRef(const std::string& text) {
	return texts.at(text);
}

