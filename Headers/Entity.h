#pragma once
#include <SFML/Graphics.hpp>
#include "AnimationHandler.h"
#include "TextureManager.h"
#include "Game.h"

class Entity {
	protected:
		AnimationHandler animHandler;
		Game* game;

	public :
		float xpos;
		float ypos;
		bool alive;
		int health;
		int movespeed;
		int fireRate;
		sf::Sprite sprite;

		virtual void move(const float dt);
		virtual void move(const float dt, bool move_right);

		void fire(const float dt);
		virtual void death();
		
		void setPosition();
		void setPosition(float x, float y);

		Entity(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, Game* game_);
};