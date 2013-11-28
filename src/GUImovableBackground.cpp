#include "GUImovableBackground.h"


MovableBackground::MovableBackground()
{
	bgSpeed = 0.3;

	bgTex.loadFromFile("graphics//background.jpg");
	bgTex.setSmooth(false);
	bgTex.setRepeated(true);
    bgSprite.setTexture(bgTex);
    bgSprite.setPosition(0,0);
    bgY = 0;
    bgSprite.setTextureRect(sf::IntRect(0,bgY,800,600));

}

void MovableBackground::Update(sf::RenderWindow &window, float elapsedTime)
{
	if (bgY < 600)
	{
		bgY -= bgSpeed * elapsedTime;
	}else 
		{
			bgY = 0;
		}
	bgSprite.setTextureRect(sf::IntRect(0, bgY, 800, 600));
}

void MovableBackground::Render(sf::RenderWindow &window)
{
	window.draw(bgSprite);
}
