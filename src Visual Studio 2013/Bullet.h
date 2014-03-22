//Bullet.h

#ifndef _BULLET_H
#define _BULLET_H

//SFML and windows header
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	void Update(float elapsedTime);
	void Render(sf::RenderWindow &window);
	void SetPosition(float x, float y);
	Bullet();
	int getDamage();
	bool active;
	bool isPew;
	sf::Sprite sprite;
private:
	float speed;
	static sf::Texture bulletTex;

};
#endif