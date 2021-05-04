#include "../Headers/Bullet.h"

Bullet::Bullet(float xpos_, float ypos_, Game* game_)
	: Entity(health, movespeed, fireRate, xpos, ypos, game_) {
	game = game_;
	health = 1;
	movespeed = 100;
	fireRate = 1;
	xpos = xpos_;
	ypos = ypos_;
	alive = true;
	if (game != nullptr) {
		sprite.setTexture(game->textureManager.getRef("bullet"));
	}
	setPosition(xpos, ypos);
}

void Bullet::move(const float dt, bool move_positive) {
	// Move vertically (right == up, left == down)
	if (move_positive) {
		ypos += movespeed * dt;
	}
	else {
		ypos -= movespeed * dt;
	}

	setPosition(xpos, ypos);
}

void Bullet::death() {
	alive = false;
	// play death animation

	// remove it from the list of enemies? something like that
	std::cout << "Boom!" << std::endl;
	delete this;
}