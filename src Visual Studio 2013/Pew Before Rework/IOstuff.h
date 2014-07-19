//IOstuff.h

#ifndef IOSTUFF_H
#define IOSTUFF_H

#include <fstream>
#include <iostream>
#include <string>


/*
To read and write .txt files
*/

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Difficulty

to set the difficulty
1 = easy
2 = normal
3 = crazy
*/

class IOdiff
{
public:
	int ReadDiffSettings();
	void WriteDiffSettings(int &diff);
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Highscore

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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

//returnes or sets if window is fullscreen or 800x600

class IOscreen
{
public:
	bool getScreenSettings();
	void setScreenSettings(bool &screen);
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*
to set the graphics smooth or not 
controlled with a bool by SFML
*/

class IOsmooth
{
public:
	bool ReadSmoothSettings();
	void WriteSmoothSettings(bool &smooth);
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

//read and write volume of sound and music

class IOsound
{
public:
	void ReadSoundSettings(int &volume);
	void WriteSoundSettings(int &volume);
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

//for Coop

class IOtwoPlayer
{
public:
	bool ReadSettings();
	void WriteSettings(bool &twoPlayer);
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif