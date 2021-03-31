#pragma once
#include <SFML/Graphics.hpp>
#include "AnimationHandler.h"

class Entity {
	private:
		AnimationHandler animHandler;
		sf::Sprite sprite;

	public :
		float xpos;
		float ypos;
		bool alive;
		int health;
		int movespeed;
		int fireRate;

		virtual void move(const float dt);
		void fire(const float dt);
		virtual void death();

		Entity(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_);
};