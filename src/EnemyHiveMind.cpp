#pragma once
#include "../Headers/EnemyHiveMind.h"

EnemyHiveMind::EnemyHiveMind(int noOfEnemiesInRow, int noOfRows) {

}

void EnemyHiveMind::move() {
	// If the hivemind controls movement, maybe it should be an entity?
}

void EnemyHiveMind::changeDirection() {
	// Move the enemy array in the other direction
	moveRight = !moveRight;
}

void EnemyHiveMind::approach() {
	// Move enemies towards the player by one row
}

void EnemyHiveMind::pickShooter() {
	// Randomly choose an enemy to shoot
}

void EnemyHiveMind::removeFromRow() {
}