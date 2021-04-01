#pragma once
#include "Entity.h"
class PlayerShip : Entity {
private:

public:
	virtual void move(const float dt);
	virtual void death();
	sf::Sprite* spritePtr;
	PlayerShip(int health_ = 1, int movespeed_ = 5, int fireRate_ = 1, float xpos_ = 0, float ypos_ = 0);
};