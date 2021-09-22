#pragma once
#include "Entity.h"
#include "Bullet.h"
class PlayerShip : public Entity {
private:

public:
	void move(const float dt, bool move_right) override;
	void death() override;
	void fire(const float dt, std::vector<Entity*>* drawVec) override;

	sf::Time previous_shot_time;

	PlayerShip(int health_ = 1, int movespeed_ = 5, int fireRate_ = 1, int xpos_ = 0, int ypos_ = 0, bool collides_ = false, Game* game_ = nullptr);
};