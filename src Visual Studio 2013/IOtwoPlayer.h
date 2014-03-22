//IOtwoPlayer.h

#ifndef IOTWOPLAYER_H
#define IOTWOPLAYER_H

#include <fstream>

class IOtwoPlayer
{
public:
	bool ReadSettings();
	void WriteSettings(bool &twoPlayer);
};

#endif