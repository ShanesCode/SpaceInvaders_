#include "../Headers/Entity.h"

Entity::Entity(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, Game* game_) {
	game = game_;
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	xpos = xpos_;
	ypos = ypos_;
	alive = true;
}

void Entity::move(const float dt) {}

void Entity::fire(const float dt) {
	int readyTimer = 0;

	// Only fire when ready
	if (readyTimer <= 0) {
		// Create projectile with velocity
		// Bullet bullet(health, movespeed, 0, xpos, ypos + offset);
		readyTimer = fireRate * 60;
	}

	// Decrease ready timer
	while (readyTimer > 0) {
		readyTimer -= dt;
	}
}

void Entity::death() {}

void Entity::setPosition(float x, float y) {
	xpos = x;
	ypos = y;
}