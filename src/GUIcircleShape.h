#ifndef GUICIRCLESHAPE_H
#define GUICIRCLESHAPE_H

//SMFL and windows header
#include <SFML\Graphics.hpp>
#include <string.h>

class GUIcircleShape
{
public:
	GUIcircleShape();
	void Update(bool &pewOnCooldown, float &elapsedTime);
	void Render(sf::RenderWindow &window);
private:
	sf::Texture texture;
	sf::CircleShape shape;
	float speed;
	float texY;
};

#endif