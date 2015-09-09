//Settings.h

#ifndef SETTINGS_H
#define SETTINGS_H

#include "Game.h"
#include "MenuSfx.h"
#include "IOstuff.h"

class Settings : public GameState{
public:
	Settings();
	~Settings();

	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);
	
private:
	int selection = 0;
	int volume;

	//myStuff
	IOsound iosound;
	MenuSound sound;
	Background bg;
	Text difficulty, graphics, sounds, back;
};

#endif