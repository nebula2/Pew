//IOHighscore.h

#ifndef IOHIGHSCORE_H
#define IOHIGHSCORE_H

#include <iostream>
#include <fstream>
#include <string>
#include "HighscoreManager.h"

class IOHighscore
{
public:

	void WriteHighscore(HighscoreManager &highscore);

private:
	std::ifstream readInFile;
	std::ofstream writeInFile;
	void openRead();
	void openWrite();
	void closeRead();
	void closeWrite();
};
#endif