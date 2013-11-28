#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <SFML\Graphics.hpp>

class Healthbar
{
public:
	Healthbar();
	void Update(sf::RenderWindow &window, int health);
	void RenderBG(sf::RenderWindow &window);
	void Render(sf::RenderWindow &window);
private:
	sf::Texture hbTex;
	sf::Texture hbBG;
	sf::Sprite	hbSprite;
	sf::Sprite	hbBGSprite;
	
};
#endif