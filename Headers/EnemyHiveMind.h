#pragma once
#include "Enemy.h"

class EnemyHiveMind {
private:
	bool moveRight;
	Enemy& leftMost;
	Enemy& rightMost;
	std::vector<Enemy&> EnemyRow;
	std::vector<std::vector<Enemy&>> Enemy2DArray;
	void changeDirection();
	void approach();
	void move();
	void pickShooter();
public:
	EnemyHiveMind(int noOfEnemiesInRow, int noOfRows);
	void removeFromRow();
};