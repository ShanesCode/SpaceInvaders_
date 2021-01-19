#pragma once
#include "Entity.h"
class Enemy: Entity {
	private:
		int bulletspeed;

	public:
		int move();
		int shoot();
};