#pragma once
#include "Entity.h"
class Bullet : public Entity {
private:

public:
	void move(const float dt, bool move_down) override;
	void death() override;

	Bullet(float xpos_, float ypos_, Game* game_);
};