#pragma once
#include "Entity.h"
class PlayerShip : public Entity {
private:

public:
	void move(const float dt) override;
	void death() override;
	sf::Sprite sprite;
	PlayerShip(int health_ = 1, int movespeed_ = 5, int fireRate_ = 1, float xpos_ = 0, float ypos_ = 0, Game* game_ = nullptr);
};