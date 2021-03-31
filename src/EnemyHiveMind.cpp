#include "../Headers/EnemyHiveMind.h"

EnemyHiveMind::EnemyHiveMind(int noOfEnemiesInRow, int noOfRows) {
	// Tile size should be the size of the whole grid (or width of the game window) divided by the number of tiles
	tile_size = 32.0;
	populate(noOfEnemiesInRow, noOfRows);
	// First enemy in the 2D array
	leftMost = Enemy2DArray[0][0];
	// Last enemy in the 2D array
	rightMost = Enemy2DArray[Enemy2DArray.size()][Enemy2DArray[Enemy2DArray.size()].size()];
}

void EnemyHiveMind::move() {
	if (moveRight) {
		xpos += tile_size;
	}
	else {
		xpos -= tile_size;
	}
}

void EnemyHiveMind::changeDirection() {
	// Move the enemy array in the other direction
	moveRight = !moveRight;
}

void EnemyHiveMind::approach() {
	// Move enemies towards the player by one row
	ypos += tile_size;
}

void EnemyHiveMind::pickShooter() {
	// Randomly choose an enemy to shoot
}

void EnemyHiveMind::removeFromRow() {
}

void EnemyHiveMind::populate(int noOfEnemiesInRow, int noOfRows) {
	int EnemyHealth = 1;
	int moveSpeed = 0;
	int fireRate = 1;
	for (int i = 0; i < noOfRows; i++) {
		std::vector<Enemy*> EnemyRow;
		for (int j = 0; j < noOfEnemiesInRow; j++) {
			Enemy enemy = Enemy(EnemyHealth, moveSpeed, fireRate, j * tile_size, i * tile_size);
			EnemyRow.push_back(&enemy);
		}
		Enemy2DArray.push_back(EnemyRow);
	}
}