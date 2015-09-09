//Boss3firstWeapon.h

#ifndef BOSS3FIRSTWEAPON_H
#define BOSS3FIRSTWEAPON_H

#include <SFML/Graphics.hpp>
#include "IOstuff.h"

class Boss3firstWeapon{
public:
	Boss3firstWeapon();
	void Update(sf::RenderWindow &window, float &elapsedTime);
	void Render(sf::RenderWindow &window);
	void setPosition(float x, float y);
	bool active;
	sf::Sprite sprite;
	int getDamage();
private:
	float speed;
	static sf::Texture weaponTex;
	bool hasTargetTexture;
};

#endif