//Bullet.h

#ifndef _BULLET_H
#define _BULLET_H

//SFML and windows header
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	void Update(sf::RenderWindow &Window, float elapsedTime);
	void Render(sf::RenderWindow &Window);
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