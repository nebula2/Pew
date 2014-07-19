//IOscreen.h

//returnes or sets if window is fullscreen or 800x600

#ifndef IOSCREEN_H
#define IOSCREEN_H

#include <fstream>


class IOscreen
{
public:
	bool getScreenSettings();
	void setScreenSettings(bool &screen);
};

#endif