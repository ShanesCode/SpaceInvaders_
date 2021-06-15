#include "../Headers/TextureManager.h"

void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
	// Load the texture
	sf::Texture texture;
	texture.loadFromFile(filename);

	textures[name] = texture;
}

void TextureManager::loadTexture(const std::string& name, const std::string& filename, const sf::IntRect& area = sf::IntRect()) {
	// Load the texture
	sf::Texture texture;
	texture.loadFromFile(filename, area);

	textures[name] = texture;
}

sf::Texture& TextureManager::getRef(const std::string& texture) {
	return textures.at(texture);
}