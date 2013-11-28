#ifndef BACKGROUNDS_H
#define BACKGROUNDS_H

#include <SFML\Graphics.hpp>

class Backgrounds
{
public:
	Backgrounds(std::string texture);
	void Render(sf::RenderWindow &window);
private:
	sf::Texture bgTex;
	sf::Sprite	bgSprite;
};
#endif