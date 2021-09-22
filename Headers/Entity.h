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
		int xpos;
		int ypos;
		bool alive;
		int health;
		int movespeed;
		int fireRate;
		sf::Sprite sprite;
		sf::Sound sound;
		bool collides;

		virtual void move(const float dt);
		virtual void move(const float dt, bool move_positive);

		virtual void fire(const float dt, std::vector<Entity*>* entitiesVec);
		virtual void death();
		
		void setPosition();
		void setPosition(float x, float y);

		virtual bool detectCollision(Entity& other);

		virtual void onCollision();

		Entity(int health_ = 1, int movespeed_ = 5, int fireRate_ = 1, int xpos_ = 0, int ypos_ = 0, bool collides = false, Game* game_ = nullptr);
};