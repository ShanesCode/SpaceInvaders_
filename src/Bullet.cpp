#include "../Headers/Bullet.h"

Bullet::Bullet(float xpos_, float ypos_, Game* game_)
	: Entity(health, movespeed, fireRate, xpos, ypos, game_) {
	game = game_;
	health = 1;
	movespeed = 750;
	fireRate = 1;
	xpos = xpos_;
	ypos = ypos_;
	alive = true;
	if (game != nullptr) {
		sprite.setTexture(game->textureManager.getRef("bullet"));
	}
	setPosition(xpos, ypos);
}

void Bullet::move(const float dt, bool move_down) {
	// Move vertically (right == up, left == down)
	if (move_down) {
		ypos += movespeed * dt;
	}
	else {
		ypos -= movespeed * dt;
	}

	setPosition(xpos, ypos);
}

void Bullet::death() {
	alive = false;
	collides = false;

	// Bullets are currently being created and deleted dynamically, so the rest of this stuff is being handled
	// In the gameScene and this just being used as a flag.. probably not the best way to do it

	//sprite.setTexture(game->textureManager.getRef("bullet_miss"));

	//delete this;
}

void Bullet::onCollision() {
	death();
}