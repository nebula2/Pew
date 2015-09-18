//HealthDrop.cpp

#include "HealthDrop.h"

sf::Texture HealthDrop::healthDropTex;

HealthDrop::HealthDrop(){
	speed = 0.2f;
	m_active = true;

	healthDropTex.loadFromFile("graphics/health_drop.png");
	healthDropTex.setSmooth(false);
	healthDropSprite.setTexture(healthDropTex);
	healthDropSprite.setOrigin(12.5, 11.5);
}

void HealthDrop::Update(sf::RenderWindow &window, float elapsedTime){
	if (m_active){
		float x = healthDropSprite.getPosition().x;
		float y = healthDropSprite.getPosition().y;

		if (y <= window.getSize().y)
			y += speed*elapsedTime;

		else
			m_active = false;

		healthDropSprite.setPosition(x, y);
	}
}

void HealthDrop::Render(sf::RenderWindow &window){
	if (m_active)
		window.draw(healthDropSprite);
}

void HealthDrop::SetPosition(float x, float y){
	healthDropSprite.setPosition(x, y);
}
//sets the entity active or inactive
void HealthDrop::setActiveBool(bool active){
	m_active = active;
}
