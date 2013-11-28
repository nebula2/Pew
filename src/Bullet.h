#ifndef _BULLET_H
#define _BULLET_H

//SFML and windows header
#include <SFML\Graphics.hpp>
#include <iostream>

class Bullet
{
public:
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void SetPosition(float x, float y);
	Bullet();
	int getDamage();

	bool active;
	sf::Sprite bulletSprite;
private:
	float speed;
	static sf::Texture bulletTex;
};
#endif