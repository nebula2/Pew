//Cow.h

#ifndef COW_H
#define COW_H

#include <SFML/Graphics.hpp>
#include "IOstuff.h"

class Cow{
public:
	Cow();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void setPosition(float x, float y);
	int getDamage();
	sf::Sprite sprite;
	bool active;
private:
	float speed;
	static sf::Texture cowTex;
	int damage;
	bool hasTargetTexture;
};

#endif