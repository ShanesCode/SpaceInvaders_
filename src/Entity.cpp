#include "../Headers/Entity.h"

Entity::Entity(int health_, int movespeed_, int fireRate_, float x_location_, float y_location_) {
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	x_location = x_location_;
	y_location = y_location_;
	alive = true;
}

void Entity::move(const float dt) {}

void Entity::fire(const float dt) {
	int readyTimer = 0;

	// Only fire when ready
	if (readyTimer <= 0) {
		// Create projectile with velocity
		// Bullet bullet(health, movespeed, 0, x_location, y_location + offset);
		readyTimer = fireRate * 60;
	}

	// Decrease ready timer
	while (readyTimer > 0) {
		readyTimer -= dt;
	}
}

void Entity::death() {}