#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {
private:
	// Map of textures
	std::map<std::string, sf::Texture> textures;

public:
	// Add a texture from a file
	void loadTexture(const std::string& name, const std::string& filename);
	void loadTexture(const std::string& name, const std::string& filename, const sf::IntRect& area);

	// Translate an id into a reference
	sf::Texture& getRef(const std::string& texture);
};