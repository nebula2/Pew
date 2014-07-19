//IOdiff.h

/*
to set the difficulty
1 = easy
2 = normal
3 = crazy
*/

#ifndef IODIFF_H
#define IODIFF_H

#include <fstream>

class IOdiff
{
public:
	int ReadDiffSettings();
	void WriteDiffSettings(int &diff);
};

#endif