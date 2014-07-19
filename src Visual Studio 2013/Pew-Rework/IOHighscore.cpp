//IOHighscore.cpp

#include "IOHighscore.h"


void IOHighscore::openWrite()
{
	IOHighscore::writeInFile.open("highscore.txt", std::ios::out | std::ios::app);
	if (!writeInFile)
	{
		std::cerr << "Could not open File";
	}
}

void IOHighscore::closeWrite()
{
	IOHighscore::writeInFile.close();
}

void IOHighscore::WriteHighscore(HighscoreManager &highscore)
{
	int mPoints = highscore.getPoints();
	int meMissed = highscore.getEnemyMissed();
	int meKilled = highscore.getEnemyKilled();
	int mmKilled = highscore.getMonkeyKilled();
	int msFired = highscore.getShotsFired();
	int msGotS = highscore.getShotsGot();

	IOHighscore::openWrite();

	IOHighscore::writeInFile << "Points " << mPoints << "," << "Enemy Missed " << meMissed << "," << "Enemy Killed " << meKilled << ","
		<< "Monkey Killed " << mmKilled << "," << "Shots Fired " << msFired << "," << "Shots Got " << msGotS << "\n";
	IOHighscore::closeWrite();
}



