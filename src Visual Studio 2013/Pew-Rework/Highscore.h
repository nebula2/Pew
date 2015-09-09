//Highscore.h

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <SFML/Graphics.hpp>
#include <sstream>

#include "Game.h"
#include "HighscoreManager.h"
#include "IOstuff.h"

class Highscore : public GameState{
public:
	Highscore();
	~Highscore();

	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);

private:

	//mystuff
	HighscoreManager mng;
	IOHighscore ioHighscore;
	Background bg;
	Text pointText, eMissedText, eKilledText, mKilledText, sFiredText, sGotText;

	//streams
	std::stringstream pointsStream;
	std::stringstream eMissedStream;
	std::stringstream eKilledStream;
	std::stringstream mKilledStream;
	std::stringstream sFiredStream;
	std::stringstream sGotStream;
};

#endif