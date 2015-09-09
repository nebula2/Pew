//IOstuff.cpp

#include "IOstuff.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

int IOdiff::ReadDiffSettings(){
	int m_diff;
	std::ifstream readInFile;
	readInFile.open("stuff//diffSettings.txt", std::ios::in);
	readInFile >> m_diff;

	//make sure diff is between the states in header
	if (m_diff > 3)
		m_diff = 3;

	if (m_diff < 1)
		m_diff = 1;

	readInFile.close();
	return m_diff;
}

void IOdiff::WriteDiffSettings(int &diff){
	std::ofstream writeInFile;
	writeInFile.open("stuff//diffSettings.txt", std::ios::out);
	writeInFile << diff;
	writeInFile.close();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

void IOHighscore::openWrite(){
	IOHighscore::writeInFile.open("highscore.txt", std::ios::out | std::ios::app);
	if (!writeInFile)
		std::cerr << "Could not open File";
}

void IOHighscore::closeWrite(){
	IOHighscore::writeInFile.close();
}

void IOHighscore::WriteHighscore(HighscoreManager &highscore){
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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool IOscreen::getScreenSettings(){
	std::ifstream readInFile;
	readInFile.open("stuff//screenSettings.txt", std::ios::in);
	bool temp;
	readInFile >> temp;
	readInFile.close();
	return temp;
}

void IOscreen::setScreenSettings(bool &screen){
	std::ofstream writeInFile;
	writeInFile.open("stuff//screenSettings.txt", std::ios::out);
	writeInFile << screen;
	writeInFile.close();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool IOsmooth::ReadSmoothSettings(){
	bool smooth;
	std::ifstream readInFile;
	readInFile.open("stuff//smoothSettings.txt", std::ios::in);
	readInFile >> smooth;
	readInFile.close();
	return smooth;
}

void IOsmooth::WriteSmoothSettings(bool &smooth){
	std::ofstream writeInFile;
	writeInFile.open("stuff//smoothSettings.txt", std::ios::out);
	writeInFile << smooth;
	writeInFile.close();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

void IOsound::ReadSoundSettings(int &volume){
	std::ifstream readInFile;
	readInFile.open("stuff//soundSettings.txt", std::ios::in);
	if (!readInFile)
		std::cerr << "Could not open sound settings";

	readInFile >> volume;
	readInFile.close();
}

void IOsound::WriteSoundSettings(int &volume){
	std::ofstream writeInFile;
	writeInFile.open("stuff//soundSettings.txt", std::ios::out);
	if (!writeInFile)
		std::cerr << "Could not open sound settings";

	writeInFile << volume;
	writeInFile.close();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool IOtwoPlayer::ReadSettings(){
	bool twoPlayer;
	std::ifstream readInFile;
	readInFile.open("stuff//twoplayer.txt", std::ios::in);
	readInFile >> twoPlayer;
	readInFile.close();
	return twoPlayer;
}

void IOtwoPlayer::WriteSettings(bool &twoPlayer){
	std::ofstream writeInFile;
	writeInFile.open("stuff//twoplayer.txt", std::ios::out);
	writeInFile << twoPlayer;
	writeInFile.close();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++
