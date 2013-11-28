#ifndef HIGHSCORE_H
#define HIGHSCORE_H

//SFML and windows header
#include <SFML\Graphics.hpp>
#include <sstream>

//own header
#include "WindowState.h"
#include "HighscoreManager.h"
#include "GUIbackgrounds.h"
#include "GUItext.h"

class Highscore : public WindowState
{
public:
	virtual int Run(sf::RenderWindow &window);
	void setHighscoreManager(HighscoreManager pMng);
private:
	sf::Event event;
	HighscoreManager mng;

	//streams
	std::stringstream pointsStream;
	std::stringstream eMissedStream;
	std::stringstream eKilledStream;
	std::stringstream mKilledStream;
	std::stringstream sFiredStream;
	std::stringstream sGotStream;

};

#endif