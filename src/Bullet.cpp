#include "../Headers/Bullet.h"

Bullet::Bullet(float xpos_, float ypos_, Game* game_)
	: Entity(health, movespeed, fireRate, xpos, ypos, game_) {
	game = game_;
	health = 1;
	movespeed = 30;
	fireRate = 1;
	xpos = xpos_;
	ypos = ypos_;
	alive = true;
	if (game != nullptr) {
		sprite.setTexture(game->textureManager.getRef("bullet"));
	}
	setPosition(xpos, ypos);
}

void Bullet::move(const float dt, bool move_right) {
	// Move vertically (right == up, left == down)
	if (move_right) {
		xpos += movespeed * dt;
	}
	else {
		xpos -= movespeed * dt;
	}

	setPosition(xpos, ypos);
}

void Bullet::death() {
	if (health == 0) {
		alive = false;
		// play death animation

		// remove it from the list of enemies? something like that
		delete this;
	}
}