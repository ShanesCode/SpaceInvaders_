#include "../Headers/Saucer.h"

// Saucer is the thing that occasionally goes across the top of the screen for extra points
Saucer::Saucer(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, bool collides_, Game* game_)
	: Entity(health_, movespeed_, fireRate_, xpos_, ypos_, collides_, game_) {
	game = game_;
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	xpos = xpos_;
	ypos = ypos_;
	collides = collides_;
	alive = true;
	points = 100;
	if (game != nullptr) {
		sprite.setTexture(game->textureManager.getRef("saucer"));
	}
	setPosition(xpos, ypos);
}

void Saucer::move(const float dt) {
	xpos -= movespeed * dt;
	setPosition(xpos, ypos);
}

void Saucer::death() {
	alive = false;
	// play death animation
	playDeathSound();
	// remove it from the list of enemies? something like that
	game->score += points;
	sprite.setTexture(game->textureManager.getRef("saucer_death"));
}

void Saucer::playSound() {
	game->audioManager.playSound(true, game->config->volume, sound, "saucer_move");
}

void Saucer::playDeathSound() {
	game->audioManager.playSound(false, game->config->volume, sound, "saucer_death");
}

void Saucer::despawn() {
	alive = false;
	game->audioManager.stopSound(sound);
}

void Saucer::onCollision() {
	death();
}