#include "../Headers/TextureManager.h"

void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
	// Load the texture
	sf::Texture texture;
	texture.loadFromFile(filename);

	this->textures[name] = texture;
}

sf::Texture& TextureManager::getRef(const std::string& texture) {
	return this->textures.at(texture);
}