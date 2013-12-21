//Boss2Weapon.h

#ifndef BOSS2WEAPON_H
#define BOSS2WEAPON_H

#include <SFML\Graphics.hpp>
#include "Player.h"

class Boss2Weapon
{
public:
	Boss2Weapon();
	void Update(sf::RenderWindow &window, float &elapsedTime, Player &pPlayer);
	void Render(sf::RenderWindow &window);
	void setPosition(float x, float y);
	bool active;
	sf::Sprite sprite;
	int getDamage();
private:
	float speed;
	static sf::Texture weaponTex;
};

#endif