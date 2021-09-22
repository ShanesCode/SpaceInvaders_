#include "../Headers/Building.h"

Building::Building(int xpos_, int ypos_, bool collides_, Game* game_)
: Entity(0, 0, 0, xpos_, ypos_, collides_, game_) {
	xpos = xpos_;
	ypos = ypos_;
	collides = collides_;
	game = game_;
	if (game != nullptr) {
		sprite.setTexture(game->textureManager.getRef("building"));
	}
}

void Building::onCollision() {
	// Get the pixel being hit
	


	// Remove pixels around where the collision happened

	// Get an image version of the texture so that you can manipulate it
	tex = game->textureManager.getRef("building");
	sf::Image image = tex.copyToImage();
	int width = image.getSize().x;
	int height = image.getSize().y;

	sf::Color hitColour = sf::Color::Red;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (image.getPixel(i, j).a > 128) {
				image.setPixel(i, j, hitColour);
			}
		}
	}

	// Replace the texture with the image
	tex.loadFromImage(image);
	sprite.setTexture(tex);
}