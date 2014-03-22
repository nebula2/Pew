//IOsound.cpp

#include "IOsound.h"

	void IOsound::ReadSoundSettings(int &volume)
	{
		std::ifstream readInFile;
		readInFile.open("stuff//soundSettings.txt", std::ios::in);
		if (!readInFile)
		{
			std::cerr << "Could not open sound settings";
		}

		readInFile >> volume;

		readInFile.close();
	}

	void IOsound::WriteSoundSettings(int &volume)
	{
		std::ofstream writeInFile;
		writeInFile.open("stuff//soundSettings.txt", std::ios::out);
		if (!writeInFile)
		{
			std::cerr << "Could not open sound settings";
		}

		writeInFile << volume;

		writeInFile.close();
	}
