//Intro.h

#ifndef INTRO_H
#define INTRO_H

#include "Game.h"


class Intro : public GameState{
public:
	Intro();
	~Intro();

	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);

private:
	sf::Clock   pClock;
	sf::Texture intro;
	sf::Sprite  introSprite;
	float elapsedTime;
	float bgSpeed, y;
};

#endif