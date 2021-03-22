#include "../Headers/Enemy.h"

Enemy::Enemy(int health_, int movespeed_, int fireRate_, float x_location_, float y_location_) {
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	x_location = x_location_;
	y_location = y_location_;
	alive = true;
}

void Enemy::move(const float dt) {
	// Move in direction of block
	// Change if sidemost hits wall
	if (sidemost) {
		// If hit wall
		changeDirection();
	}
}

void Enemy::death() {

}

void Enemy::changeDirection() {

}