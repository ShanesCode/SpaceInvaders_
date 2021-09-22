#pragma once
#include "Enemy.h"

// Have a y and x offset
// Enemy types are the same for each row

class EnemyHiveMind {
private:
	int xpos;
	int ypos;
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