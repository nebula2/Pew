#ifndef GUIDIV_H
#define GUIDIV_H

#include <SFML\Graphics.hpp>

class Diverses
{
public:
	 Diverses(std::string texture);
	~Diverses();
	void SetPosition(float x, float y);
	void Render(sf::RenderWindow &window);
	sf::Vector2f GetPosition();

	sf::Texture divTex;
	sf::Sprite divSprite;

};

#endif