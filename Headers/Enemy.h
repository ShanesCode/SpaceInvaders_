#pragma once
#include "Entity.h"
#include "Bullet.h"
class Enemy: public Entity {
	private:
		// Bool to check if this enemy is at the edge of the "block" of enemies
		// If a sidemost hits the edge of the screen, all enemies change direction
		bool sidemost;
		void changeDirection();
		int type;
		void playDeathSound();

	public:
		void move(const float dt) override;
		void death() override;

		void fire(const float dt, std::vector<Entity*>* entitiesVec) override;

		int points;

		void onCollision() override;

		Enemy(int type_ = 0, int health_ = 1, int movespeed_ = 0, int fireRate_ = 0, float xpos_ = 0.0f, float ypos_ = 0.0f, bool collides_ = false, int points = 10, Game* game_ = nullptr);
};