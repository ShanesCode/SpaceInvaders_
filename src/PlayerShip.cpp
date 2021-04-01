#include "../Headers/PlayerShip.h"

PlayerShip::PlayerShip(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_)
	: Entity(health_, movespeed_, fireRate_, xpos_, ypos_, textureManager) {
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	xpos = xpos_;
	ypos = ypos_;
	alive = true;
	spritePtr = &sprite;
	spritePtr->setTexture(textureManager->getRef("player"));
}

void PlayerShip::move(const float dt) {
	// Move horizontally of block

}

void PlayerShip::death() {
	if (health == 0) {
		alive = false;
		// play death animation

		// remove it from the list of enemies? something like that
	}
}