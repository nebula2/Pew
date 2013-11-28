#include "Healthbar.h"

Healthbar::Healthbar()
{
	hbTex.loadFromFile("graphics//healthbar.jpg");
	hbTex.setSmooth(false);
	hbSprite.setTexture(hbTex);
	hbSprite.setPosition(71.55, 13);

	hbBG.loadFromFile("graphics//healthbarBG.jpg");
	hbBG.setSmooth(false);
	hbBGSprite.setTexture(hbBG);
	hbBGSprite.setPosition(70, 13);
}

void Healthbar::Update(sf::RenderWindow &window, int health)
{
	if (health <= 100)
	{
	health = 100 - health;
	float x = hbSprite.getPosition().x;
	static_cast<float>(health);
	health *= 1.55;
	hbSprite.setPosition(71.55-health, 13);
	
	}

}

void Healthbar::RenderBG(sf::RenderWindow &window)
{
	window.draw(hbBGSprite);
}

void Healthbar::Render(sf::RenderWindow &window)
{
	window.draw(hbSprite);
}
