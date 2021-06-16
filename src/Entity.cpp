#include "../Headers/Entity.h"

Entity::Entity(int health_, int movespeed_, int fireRate_, float xpos_, float ypos_, bool collides_, Game* game_) {
	game = game_;
	health = health_;
	movespeed = movespeed_;
	fireRate = fireRate_;
	xpos = xpos_;
	ypos = ypos_;
	alive = true;
	collides = collides_;
}

void Entity::move(const float dt) {}
void Entity::move(const float dt, bool move_positive) {}

void Entity::fire(const float dt, bool upwards, int x_offset, int y_offset, std::vector<Entity*>* entitiesVec) {}

void Entity::death() {}

void Entity::setPosition() {
	sprite.setPosition(sf::Vector2f(xpos, ypos));
}

void Entity::setPosition(float x, float y) {
	xpos = x;
	ypos = y;
	sprite.setPosition(sf::Vector2f(xpos, ypos));
}

bool Entity::detectCollision(const Entity& other) {
	if (this->collides && other.collides && sprite.getGlobalBounds().intersects(other.sprite.getGlobalBounds())) {
		std::cout << "Collision detected." << std::endl;
	}
	return this->collides && sprite.getGlobalBounds().intersects(other.sprite.getGlobalBounds());
}

void Entity::onCollision() {}