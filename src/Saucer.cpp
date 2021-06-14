#include "../Headers/Saucer.h"

// Saucer is the thing that occasionally goes across the top of the screen for extra points
Saucer::Saucer(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, Game* game_)
	: Entity(health_, movespeed_, fireRate_, xpos_, ypos_, game_) {
	game = game_;
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	xpos = xpos_;
	ypos = ypos_;
	alive = true;
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
	if (health == 0) {
		alive = false;
		// play death animation
		playDeathSound();
		// remove it from the list of enemies? something like that
	}
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