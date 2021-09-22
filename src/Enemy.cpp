#include "../Headers/Enemy.h"

Enemy::Enemy(int type_, int health_, int movespeed_, int fireRate_, int xpos_, int ypos_, bool collides_, int points_, Game* game_)
: Entity(health_, movespeed_, fireRate_, xpos_, ypos_, collides_, game_) {
	sidemost = false;
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	xpos = xpos_;
	ypos = ypos_;
	collides = collides_;
	points = points_;
	alive = true;
	type = type_;
	if (game != nullptr) {
		switch (type)
		{
		case 0:
			sprite.setTexture(game->textureManager.getRef("alien0"));
			break;
		case 1:
			sprite.setTexture(game->textureManager.getRef("alien1"));
			break;
		case 2:
			sprite.setTexture(game->textureManager.getRef("alien2"));
			break;
		default:
			break;
		}
	}
}

void Enemy::move(const float dt) {
	// Move in direction of block
	// Change if sidemost hits wall
	if (sidemost) {
		// If hit wall
		changeDirection();
	}
}

void Enemy::fire(const float dt, std::vector<Entity*>* entitiesVec) {
	// Choose who fires next
	bool upwards = false;
	int x_offset = sprite.getGlobalBounds().width / 2;
	int y_offset = sprite.getGlobalBounds().height / 2;

	Bullet* bullet = new Bullet(xpos + x_offset, ypos + y_offset, true, game);
}

void Enemy::death() {
	alive = false;
	playDeathSound();
	game->score += points;
	sprite.setTexture(game->textureManager.getRef("alien_death"));
}

void Enemy::playDeathSound() {
	game->audioManager.playSound(false, game->config->volume, sound, "saucer_death");
}

void Enemy::changeDirection() {
	// Change direction of block
	// For all enemies in the block, change their direction
}

void Enemy::onCollision() {
	death();
}