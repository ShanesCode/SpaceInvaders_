#pragma once
#include "Entity.h"
#include "Bullet.h"
class Enemy: public Entity {
	private:
		// Bool to check if this enemy is at the edge of the "block" of enemies
		// If a sidemost hits the edge of the screen, all enemies change direction
		bool sidemost;
		void changeDirection();

	public:
		void move(const float dt) override;
		void death() override;

		void fire(const float dt, std::vector<Entity*>* entitiesVec) override;

		Enemy(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, bool collides_ = false, Game* game_ = nullptr);
};