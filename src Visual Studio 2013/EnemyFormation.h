//EnemyFormation.h

#ifndef ENEMYFORMATION_H
#define ENEMYFORMATION_H

#include <SFML\Graphics.hpp>
#include "IOdiff.h"
#include "IOsmooth.h"

class EnemyFormation
{
public:
	EnemyFormation();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	//setter
	void setPosition(float x, float y);
	void reduceHealth(int pDamage);
	//getter
	int getHealth();
	int getDamage();
	sf::Sprite sprite;
	bool active;
private:
	float speed;
	static sf::Texture texture;
	int health;
	int damage;
};

#endif