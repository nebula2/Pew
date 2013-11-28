#ifndef DOUBLESHOT_H
#define DOUBLESHOT_H

//SFML and windows header
#include <SFML\Graphics.hpp>
#include <iostream>

class DoubleShot
{
public:
	DoubleShot();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void SetPosition(float x, float y);
	int getDamage();

	bool active;
	sf::Sprite doubleSprite;
private:
	float speed;
	static sf::Texture doubleTex;
};
#endif