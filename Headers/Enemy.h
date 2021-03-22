#pragma once
#include "Entity.h"
class Enemy: Entity {
	private:
		// Bool to check if this enemy is at the edge of the "block" of enemies
		// If a sidemost hits the edge of the screen, all enemies change direction
		bool sidemost;
		void changeDirection();
		void chooseShooter();

	public:
		virtual void move(const float dt);
		virtual void death();

		Enemy(int health_, int movespeed_, int fireRate_, float x_location_, float y_location_);
};