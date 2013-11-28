#ifndef _SHIT_H
#define _SHIT_H

//windows and sfml header
#include <SFML\Graphics.hpp>
#include <iostream>
//own header
#include "SpaceMonkey.h"
#include "Player.h"

class ShitBullets
{
public:
	void Update(sf::RenderWindow &Window, float elapsedTime);
	void Render(sf::RenderWindow &Window);
	void SetPosition(float x, float y);
	ShitBullets();
	bool active;
	sf::Sprite shitSprite;
	int getDamage();
private:
	sf::Vector2f pPosition;
	float speed;
	static sf::Texture shitTex;

};
#endif