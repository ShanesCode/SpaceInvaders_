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

<<<<<<< HEAD
void Enemy::chooseShooter() {
	// Choose who fires next
}

void Enemy::death() {
	if (health == 0) {
		alive = false;
		// play death animation
		
		// remove it from the list of enemies? something like that
	}
}

void Enemy::changeDirection() {
	// Change direction of block
	// For all enemies in the block, change their direction
=======
void Enemy::death() {

}

void Enemy::changeDirection() {

>>>>>>> f67df709f8569dae25d02a0410fb4fdf78cd3390
}