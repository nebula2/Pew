//GraphicSet.h

#ifndef GRAPHICSET_H
#define GRAPHICSET_H

#include "Game.h"
#include "IOstuff.h"
#include "MenuSfx.h"

class GraphicSet : public GameState{
public:
	GraphicSet();
	~GraphicSet();

	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);

private:
	bool selectionH;
	bool selectionV;
	int volume;
	bool isSmooth;
	bool isFull;

	//myStuff
	Background bg;
	IOscreen ioscreen;
	IOsmooth iosmooth;
	IOsound iosound;
	MenuSound sound;
	Text smooth, fullscreen, falseS, falseF, trueS, trueF, info;
};

#endif