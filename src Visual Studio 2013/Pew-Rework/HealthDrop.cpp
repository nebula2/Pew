//HealthDrop.cpp

#include "HealthDrop.h"

sf::Texture HealthDrop::healthDropTex;

HealthDrop::HealthDrop(){
	speed = 0.2;
	active = true;

	healthDropTex.loadFromFile("graphics//health_drop.png");
	healthDropTex.setSmooth(false);
	healthDropSprite.setTexture(healthDropTex);
	healthDropSprite.setOrigin(12.5, 11.5);
}

void HealthDrop::Update(sf::RenderWindow &window, float elapsedTime){
	if (HealthDrop::active){
		float x = healthDropSprite.getPosition().x;
		float y = healthDropSprite.getPosition().y;

		if (y <= window.getSize().y)
			y += speed*elapsedTime;

		else
			active = false;

		healthDropSprite.setPosition(x, y);
	}
}

void HealthDrop::Render(sf::RenderWindow &window){
	if (active)
		window.draw(healthDropSprite);
}

void HealthDrop::SetPosition(float x, float y){
	healthDropSprite.setPosition(x, y);
}