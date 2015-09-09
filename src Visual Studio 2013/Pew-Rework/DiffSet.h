//DiffSet.h

#ifndef DIFFSET_H
#define DIFFSET_H

#include "Game.h"
#include "IOstuff.h"
#include "MenuSfx.h"

class DiffSet : public GameState{
public:
	DiffSet();
	~DiffSet();

	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);

private:
	int selection;
	int volume;

	//MyStuff
	IOdiff diff;
	Background bg;
	IOsound iosound;
	MenuSound sound;
	Text easy, normal, crazy, info;
};

#endif