#include "GUIdiv.h"

Diverses::Diverses(std::string texture)
{
	divTex.loadFromFile(texture);
	divTex.setSmooth(false);
	divSprite.setTexture(divTex);
}

Diverses::~Diverses()
{
}

void Diverses::SetPosition(float x, float y)
{
	divSprite.setPosition(x, y);
}

sf::Vector2f Diverses::GetPosition()
{
	return divSprite.getPosition();
}

void Diverses::Render(sf::RenderWindow &window)
{
	window.draw(divSprite);
}