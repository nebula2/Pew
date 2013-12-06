//Enemy.h

#ifndef _ENEMY_H
#define _ENEMY_H

//SFML and windows header
#include <SFML\Graphics.hpp>
#include <iostream>

//own header
#include "HighscoreManager.h"

class Enemy
{
public:
	Enemy();
	void Update(sf::RenderWindow &window, float elapsedTime, HighscoreManager &highscore);
	void Render(sf::RenderWindow &window);
	//setter
	void SetPosition(float x, float y);
	void reduceHealth(int pDamage);
	//getter
	int  getHealth();
	int getDamage();

	sf::Sprite sprite;
	bool active;
private:
	float speed;
	static sf::Texture enemyTex;
	int health;
};
#endif