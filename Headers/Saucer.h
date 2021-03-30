#pragma once
#include "Entity.h"
class Saucer : Entity {
private:

public:
	virtual void move(const float dt);
	virtual void death();

	Saucer(int health_, int movespeed_, int fireRate_, float x_location_, float y_location_);
};