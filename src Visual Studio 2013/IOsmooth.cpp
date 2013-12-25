//IOsmooth.cpp

#include "IOsmooth.h"

bool IOsmooth::ReadSmoothSettings()
{
	bool smooth;
	std::ifstream readInFile;
	readInFile.open("stuff//smoothSettings.txt", std::ios::in);
	readInFile >> smooth;
	readInFile.close();
	return smooth;
}

void IOsmooth::WriteSmoothSettings(bool &smooth)
{
	std::ofstream writeInFile;
	writeInFile.open("stuff//smoothSettings.txt", std::ios::out);
	writeInFile << smooth;
	writeInFile.close();
}