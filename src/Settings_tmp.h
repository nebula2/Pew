#ifndef SETTINGS_TMP_H
#define SETTINGS_TMP_H

//SFML and windows header
#include <SFML\Graphics.hpp>

//own header
#include "WindowState.h"
#include "GUIbackgrounds.h"
#include "MenuSound.h"
#include "MenuMusic.h"

class Settings_tmp : public WindowState
{
public:
	virtual int Run (sf::RenderWindow &window);

private:
	sf::Event event;
};

#endif