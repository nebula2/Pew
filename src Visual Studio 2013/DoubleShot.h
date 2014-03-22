//DoubleShot.h

#ifndef DOUBLESHOT_H
#define DOUBLESHOT_H

//SFML and windows header
#include <SFML/Graphics.hpp>

class DoubleShot
{
public:
	DoubleShot();
	void Update(float elapsedTime);
	void Render(sf::RenderWindow &window);
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