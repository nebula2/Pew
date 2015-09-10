//MainMenuState.h

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "Game.h"
#include "MenuSfx.h"
#include "IOstuff.h"

class MainMenuState : public GameState{
public:
	MainMenuState();
	~MainMenuState();
	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);
private:
	IOsound iosound;
	MenuSound sound;
	Background bg;
	Text play, again, highscore, settings, close;

	float		speed;
	float		elapsedTime;
	float		x_movement;
	float		y_movement;
	float		x, y;
	short int   debauch;
	short int   selection;
	int		    volume;

	//sf::Event   pEvent;
	sf::Clock   pClock;
	sf::Texture texture;
	sf::Sprite  sprite;
};
#endif