//IOsound.h
//to read or write the volume of the sfx

#ifndef IOSOUNDS_H
#define IOSOUNDS_H

#include <iostream>
#include <fstream>
#include <string>

class IOsound
{
	public:
	void ReadSoundSettings(int &volume);
	void WriteSoundSettings(int &volume);
};

#endif