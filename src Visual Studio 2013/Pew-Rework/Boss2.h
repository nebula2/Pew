//Boss2.h

#ifndef BOSS2_H
#define BOSS2_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include "IOstuff.h"

class Boss2
{
public:
	Boss2();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void setPosition(float x, float y);
	void reduceHealth(int pDamage);
	int getHealth();
	int getDamage();
	bool getfadeIn();
	sf::Vector2f getPosition();
	sf::Sprite sprite;
	bool active;


private:
	float sinValue;
	float speed;
	static sf::Texture enemyTex;
	int health;
	int debauch;
	bool fadeIn;
	bool moveLeft;
};

#endif