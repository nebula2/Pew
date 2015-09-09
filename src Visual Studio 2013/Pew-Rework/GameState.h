#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GUI.h"
#include <SFML\Graphics.hpp>

class Game;

class GameState{
public:
	virtual void HandleEvents(Game &game) = 0;
	virtual void Update(Game &game) = 0;
	virtual void Render(Game &game) = 0;
	virtual		 ~GameState(){};
};

#endif