//HighscoreManager.cpp

#include "HighscoreManager.h"

HighscoreManager::HighscoreManager(){
	hSfired = 0;
	hPoints = 0;
	hMissed = 0;
	hEkilled = 0;
	hMkilled = 0;
	hSgot = 0;
}

//setter

//sets the Points the player got to the highscore
void HighscoreManager::setPoints(int points){ //in game initialized
	hPoints = points;
}

//sets the Enemies the player missed to the highscore
void HighscoreManager::setEnemyMissed(int missed){ //enemy
	hMissed += missed;
}

//sets the Enemies the player killed to the highscore
void HighscoreManager::setEnemyKilled(int ekilled){//collision
	hEkilled += ekilled;
}

//sets the Monkeys the player killed to the highscore
void HighscoreManager::setMonkeyKilled(int mkilled){//collision
	hMkilled += mkilled;
}

//sets the Shots the player fired to the highscore
void HighscoreManager::setShotsFired(int sfired){//game
	hSfired += sfired;
}

//sets the Shots the player got to the highscore
void HighscoreManager::setShotsGot(int sgot){//collision
	hSgot += sgot;
}