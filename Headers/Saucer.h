#pragma once
#include "Entity.h"
class Saucer : public Entity {
private:

public:
	void move(const float dt) override;
	void death() override;

	Saucer(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, Game* game_ = nullptr);
};