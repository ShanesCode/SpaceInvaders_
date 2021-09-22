#pragma once
#include "Entity.h"

class Building : public Entity {
	private:
		sf::Texture tex;
		std::vector<bool> active_pixels;
	public:
		void onCollision() override;

		Building(int xpos_ = 0, int ypos_ = 0, bool collides_ = true, Game* game_ = nullptr);
};