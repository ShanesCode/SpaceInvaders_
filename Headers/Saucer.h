#pragma once
#include "Entity.h"
class Saucer : public Entity {
private:

public:
	void move(const float dt) override;
	void death() override;

	void playSound();
	void playDeathSound();

	Saucer(int health_ = 1, int movespeed_ = 100, int fireRate_ = 0, float xpos_ = 0, float ypos_ = 0, Game* game_ = nullptr);
};