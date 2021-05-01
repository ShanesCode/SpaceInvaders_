#pragma once
#include "Entity.h"
class Enemy: public Entity {
	private:
		// Bool to check if this enemy is at the edge of the "block" of enemies
		// If a sidemost hits the edge of the screen, all enemies change direction
		bool sidemost;
		void changeDirection();
		void chooseShooter();

	public:
		void move(const float dt) override;
		void death() override;

		Enemy(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, Game* game_ = nullptr);
};