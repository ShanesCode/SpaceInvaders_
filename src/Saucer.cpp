#include "../Headers/Saucer.h"

// Saucer is the thing that occasionally goes across the top of the screen for extra points
Saucer::Saucer(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_)
	: Entity(health_, movespeed_, fireRate_, xpos_, ypos_) {
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	xpos = xpos_;
	ypos = ypos_;
	alive = true;
}

void Saucer::move(const float dt) {
	// Move horizontally of block

}

void Saucer::death() {
	if (health == 0) {
		alive = false;
		// play death animation

		// remove it from the list of enemies? something like that
	}
}