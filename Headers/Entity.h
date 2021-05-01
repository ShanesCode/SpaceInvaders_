#pragma once
#include <SFML/Graphics.hpp>
#include "AnimationHandler.h"
#include "TextureManager.h"
#include "Game.h"

class Entity {
	protected:
		AnimationHandler animHandler;
		sf::Sprite sprite;
		Game* game;

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
		
		void setPosition();
		void setPosition(float x, float y);

		Entity(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, Game* game_);
};