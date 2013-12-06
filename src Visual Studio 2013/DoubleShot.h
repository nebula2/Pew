//DoubleShot.h

#ifndef DOUBLESHOT_H
#define DOUBLESHOT_H

//SFML and windows header
#include <SFML\Graphics.hpp>
#include <iostream>

class DoubleShot
{
public:
	DoubleShot();
	void Update(sf::RenderWindow &Window, float elapsedTime);
	void Render(sf::RenderWindow &Window);
	void SetPosition(float x, float y);
	int getDamage();
	bool isPew;
	bool active;
	sf::Sprite sprite;
private:
	float speed;
	static sf::Texture doubleTex;
	
};
#endif