//ShitBullets.h

#ifndef _SHIT_H
#define _SHIT_H

#include <SFML/Graphics.hpp>
#include "SpaceMonkey.h"
#include "IOdiff.h"
#include "IOsmooth.h"

class ShitBullets
{
public:
	void Update(sf::RenderWindow &Window, float elapsedTime);
	void Render(sf::RenderWindow &Window);
	void SetPosition(float x, float y);
	ShitBullets();
	bool active;
	sf::Sprite sprite;
	int getDamage();
	void reduceHealth(int pDamage);
	int  getHealth();
private:
	sf::Vector2f pPosition;
	float speed;
	static sf::Texture shitTex;
};
#endif