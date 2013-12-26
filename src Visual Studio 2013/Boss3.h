//boss3.h

#ifndef BOSS3_H
#define BOss3_H

#include <SFML/Graphics.hpp>
#include "IOdiff.h"

class Boss3
{
public:
	Boss3();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void setPosition(float x, float y);
	void reduceHealth(int pDamage);
	int getDamage();
	int getHealth();

private:
	float moveSpeed;
	float shootSpeed;
	static sf::Texture enemyTex;
	int health;
};


#endif