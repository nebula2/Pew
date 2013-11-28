#include "HighscoreManager.h"

HighscoreManager::HighscoreManager()
{
	hSfired  = 0;
	hPoints  = 0;
	hMissed	 = 0;
	hEkilled = 0;
	hMkilled = 0;
	hSgot	 = 0;
}

//setter
void HighscoreManager::setPoints(int points) //in game initialized
{
	hPoints = points;
}
void HighscoreManager::setEnemyMissed(int missed) //enemy
{
	hMissed += missed;
}
void HighscoreManager::setEnemyKilled(int ekilled)//collision
{
	hEkilled += ekilled;
}
void HighscoreManager::setMonkeyKilled(int mkilled)//collision
{
	hMkilled += mkilled;
}
void HighscoreManager::setShotsFired(int sfired)//game
{
	hSfired += sfired;
}
void HighscoreManager::setShotsGot(int sgot)//collision
{
	hSgot += sgot;
}

//getter
int HighscoreManager::getPoints()
{
	return hPoints;
}
int HighscoreManager::getEnemyMissed()
{
	return hMissed;
}
int HighscoreManager::getEnemyKilled()
{
	return hEkilled;
}
int HighscoreManager::getMonkeyKilled()
{
	return hMkilled;
}
int HighscoreManager::getShotsFired()
{
	return hSfired;
}
int HighscoreManager::getShotsGot()
{
	return hSgot;
}