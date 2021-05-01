#include "../Headers/Enemy.h"

Enemy::Enemy(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, Game* game_)
: Entity(health_, movespeed_, fireRate_, xpos_, ypos_, game_) {
	sidemost = false;
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	xpos = xpos_;
	ypos = ypos_;
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
}