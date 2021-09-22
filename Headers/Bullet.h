#pragma once
#include "Entity.h"
class Bullet : public Entity {
private:

public:
	void move(const float dt, bool move_down) override;
	void death() override;
	void onCollision() override;
	Bullet(int xpos_ = 0, int ypos_ = 0, bool collides_ = false, Game* game_ = nullptr);

	bool detectCollision(Entity& other) override;
};