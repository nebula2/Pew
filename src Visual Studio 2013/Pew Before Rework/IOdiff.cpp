//IOdiff.cpp

#include "IOdiff.h"

int IOdiff::ReadDiffSettings()
{
	int m_diff;
	std::ifstream readInFile;
	readInFile.open("stuff//diffSettings.txt", std::ios::in);
	readInFile >> m_diff;
	
	//make sure diff is between the states in header
	if (m_diff > 3)
	{
		m_diff = 3;
	}
	if (m_diff < 1)
	{
		m_diff = 1;
	}
	readInFile.close();

	return m_diff;
}

void IOdiff::WriteDiffSettings(int &diff)
{
	std::ofstream writeInFile;
	writeInFile.open("stuff//diffSettings.txt", std::ios::out);
	writeInFile << diff;
	writeInFile.close();
}