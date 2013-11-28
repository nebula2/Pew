#ifndef GUIMOVABLEBACKGROUNDS_H
#define GUIMOVABLEBACKGROUNDS_H

#include <SFML\Graphics.hpp>
#include <iostream>

class MovableBackground
{
public:
	MovableBackground();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	
private:
	sf::Texture bgTex;
	sf::Sprite	bgSprite;

	float bgSpeed;
	float bgY;
};
#endif