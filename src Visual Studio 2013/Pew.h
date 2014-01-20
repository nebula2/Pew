//Pew.h

#ifndef PEW_H
#define PEW_H

//SFML and windows header
#include <SFML/Graphics.hpp>
#include <iostream>

class Pew
{
public:
	void Update(sf::RenderWindow &Window, float elapsedTime);
	void Render(sf::RenderWindow &Window);
	void SetPosition(float x, float y);
	Pew();
	int getDamage();
	bool isPew;
	bool active;
	sf::Sprite sprite;
private:
	float speed;
	static sf::Texture pewShotTex;

};
#endif