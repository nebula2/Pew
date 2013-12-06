//Boss1.h

#ifndef BOSS1_H
#define BOSS1_H

#include <SFML\Graphics.hpp>
#include <iostream>

class Boss1
{
public:
	Boss1();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void SetPosition(float x, float y);
	void reduceHealth(int pDamage);
	int  getHealth();
	sf::Vector2f getPosition();
	int getDamage();

	sf::Sprite sprite;
	bool active;
private:
	float   speed;
	static  sf::Texture enemyTex;
	int		health;
	bool	moveLeft;
};

#endif