//Boss1Weapon.h

#ifndef BOSS1WEAPON_H
#define BOSS1WEAPON_H

//windows and sfml header
#include <SFML\Graphics.hpp>
#include <iostream>
//own header
#include "SpaceMonkey.h"
#include "Player.h"

class Boss1Weapon
{
public:
	void Update(sf::RenderWindow &Window, float elapsedTime);
	void Render(sf::RenderWindow &Window);
	void SetPosition(float x, float y);
	Boss1Weapon();
	bool active;
	sf::Sprite sprite;
	int getDamage();
private:
	sf::Vector2f pPosition;
	float speed;
	static sf::Texture weaponTex;

};
#endif