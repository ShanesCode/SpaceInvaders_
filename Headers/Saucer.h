#pragma once
#include "Entity.h"
class Saucer : public Entity {
private:
	void playDeathSound();
public:
	void move(const float dt) override;
	void death() override;

	void playSound();
	void despawn();

	void onCollision() override;

	int points;

	Saucer(int health_ = 1, int movespeed_ = 100, int fireRate_ = 0, float xpos_ = 0, float ypos_ = 0, bool collides_ = false, Game* game_ = nullptr);
};