//SoundSet.h

#ifndef SOUNDSET_H
#define SOUNDSET_H

#include "Game.h"
#include "IOstuff.h"
#include <sstream>

class SoundSet : public GameState{
public:
	SoundSet();
	~SoundSet();

	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);

private:
	int volume;
	int selection;
	std::stringstream selectionStream;

	//myStuff
	Background bg;
	Text selectionString;
	IOsound iosound;
};

#endif