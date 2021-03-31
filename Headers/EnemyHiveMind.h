#pragma once
#include "Enemy.h"

class EnemyHiveMind {
private:
	float xpos;
	float ypos;
	float tile_size;

	bool moveRight;
	Enemy* leftMost;
	Enemy* rightMost;
	std::vector<std::vector<Enemy*>> Enemy2DArray;
	void populate(int noOfEnemiesInRow, int noOfRows);
	void changeDirection();
	void approach();
	void move();
	void pickShooter();
public:
	EnemyHiveMind(int noOfEnemiesInRow, int noOfRows);
	void removeFromRow();
};