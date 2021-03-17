#pragma once
#include <SFML/Graphics.hpp>
#include "AnimationHandler.h"

class Entity {
	private:
		AnimationHandler animHandler;
		sf::Sprite sprite;

	public :
		float x_location;
		float y_location;
		bool alive;
		int health;
		int movespeed;
		int fireRate;

		virtual void move(const float dt);
		void fire(const float dt);
		virtual void death();

		Entity(int health_, int movespeed_, int fireRate_, float x_location_, float y_location_);
};