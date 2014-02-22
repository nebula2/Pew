//Boss1Weapon.h

#ifndef BOSS1WEAPON_H
#define BOSS1WEAPON_H


#include <SFML/Graphics.hpp>
#include "IOstuff.h"

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