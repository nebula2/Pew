//IOtwoPlayer.cpp

#include "IOtwoPlayer.h"

bool IOtwoPlayer::ReadSettings()
{
	bool twoPlayer;
	std::ifstream readInFile;
	readInFile.open("stuff//twoplayer.txt", std::ios::in);
	readInFile >> twoPlayer;
	readInFile.close();
	return twoPlayer;
}

void IOtwoPlayer::WriteSettings(bool &twoPlayer)
{
	std::ofstream writeInFile;
	writeInFile.open("stuff//twoplayer.txt", std::ios::out);
	writeInFile << twoPlayer;
	writeInFile.close();
}