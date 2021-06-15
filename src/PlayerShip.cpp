#include "../Headers/PlayerShip.h"

PlayerShip::PlayerShip(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, Game* game_)
	: Entity(health_, movespeed_, fireRate_, xpos_, ypos_, game_) {
	game = game_;
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	xpos = xpos_;
	ypos = ypos_;
	alive = true;
	if (game != nullptr) {
		sprite.setTexture(game->textureManager.getRef("player"));
	}
	setPosition(xpos, ypos);

	previous_shot_time = sf::microseconds(0.0f);
}

void PlayerShip::move(const float dt, bool move_right) {
	// Move horizontally
	if (move_right) {
		xpos += movespeed * dt;
	}
	else {
		xpos -= movespeed * dt;
	}

	setPosition(xpos, ypos);
}

void PlayerShip::fire(const float dt, bool upwards, int x_offset, int y_offset, std::vector<Entity*>* entitiesVec) {
	int readyTimer = 0;

	// Only fire when ready
	if (readyTimer <= 0) {
		// Create projectile with velocity
		Bullet* bullet = new Bullet(xpos + x_offset, ypos + y_offset, game);
		entitiesVec->push_back(bullet);

		game->audioManager.playSound(false, game->config->volume, sound, "fire");
		readyTimer = fireRate * 60;
	}

	// Decrease ready timer
	while (readyTimer > 0) {
		readyTimer -= dt;
	}
}

void PlayerShip::death() {
	if (health == 0) {
		alive = false;
		// play death animation

		// remove it from the list of enemies? something like that
	}
}