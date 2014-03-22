//IOsmooth.h

//to set the graphics smooth or not controlled with a bool by SFML

#ifndef IOSMOOTH_H
#define IOSMOOTH_H

#include <fstream>

class IOsmooth
{
public:
	bool ReadSmoothSettings();
	void WriteSmoothSettings(bool &smooth);
};

#endif