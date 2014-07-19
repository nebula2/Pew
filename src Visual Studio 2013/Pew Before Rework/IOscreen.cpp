//IOscreen.cpp

#include "IOscreen.h"

bool IOscreen::getScreenSettings()
{
	std::ifstream readInFile;
	readInFile.open("stuff//screenSettings.txt", std::ios::in);
	bool temp;
	readInFile >> temp;
	readInFile.close();

	return temp;
}

void IOscreen::setScreenSettings(bool &screen)
{
	std::ofstream writeInFile;
	writeInFile.open("stuff//screenSettings.txt", std::ios::out);
	writeInFile << screen;
	writeInFile.close();
}
