#include "GUIcircleShape.h"

GUIcircleShape::GUIcircleShape()
{
	speed = 0.02;
	texture.loadFromFile("graphics//pewcd.png");
	texture.setSmooth(false);
	shape.setRadius(25);
	shape.setPosition(450, 0);
	texY = 0;
	shape.setTexture(&texture);
	shape.setTextureRect(sf::IntRect(450, texY, 53, 50));
	
}

void GUIcircleShape::Update(bool &pewOnCooldown, float &elapsedTime)
{
	if (pewOnCooldown)
	{
		if (texY > -50)
	{
		texY -= speed * elapsedTime;
	}else 
		{
			texY = 0;
			pewOnCooldown = false;
			
		}
	shape.setTextureRect(sf::IntRect(450, texY, 53, 50));
	}
}

void GUIcircleShape::Render(sf::RenderWindow &window)
{
	window.draw(shape);
}