#include "GUIbackgrounds.h"

Backgrounds::Backgrounds(std::string texture)
{
	bgTex.loadFromFile(texture);
	bgTex.setSmooth(false);
	bgSprite.setTexture(bgTex);
	bgSprite.setPosition(0, 0);
}

void Backgrounds::Render(sf::RenderWindow &window)
{
	window.draw(bgSprite);
}