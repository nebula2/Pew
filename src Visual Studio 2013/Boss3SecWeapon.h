//Boss3SecWeapon.h
#ifndef BOSS3SECWEAPON_H
#define BOSS3SECWEAPON_H

#include <SFML/Graphics.hpp>
#include "IOstuff.h"

class Boss3SecWeapon
{
public:
	Boss3SecWeapon();
	void Update(sf::RenderWindow &window, float &elapsedTime);
	void Render(sf::RenderWindow &window);
	void setPosition(float x, float y);
	int getDamage();
	void reduceHealth(int pDamage);
	int  getHealth();
	bool active;
	sf::Sprite sprite;

private:
	float speed;
	static sf::Texture weaponTex;
	int health;
};
#endif