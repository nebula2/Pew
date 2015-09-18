//Cow.cpp

#include "Cow.h"

sf::Texture Cow::cowTex;

Cow::Cow(){
	IOdiff diff;
	IOsmooth smooth;
	hasTargetTexture = false;
	speed = 0.5 *diff.ReadDiffSettings();
	m_active = true;
	damage = 25;

	cowTex.loadFromFile("graphics/enemies/cow.png");
	cowTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(cowTex);
	sprite.setOrigin(0, 300);
}

void Cow::Update(sf::RenderWindow &window, float elapsedTime){
	if (m_active){
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y <= window.getSize().y * 1.5){
			if (y <= window.getSize().y / 4)
				y += (speed / 4) * elapsedTime;
			
			else
				y += speed * elapsedTime;
		}
		else if (y >= window.getSize().y * 1.5)
			m_active = false;
		
		sprite.setPosition(x, y);
	}
}

void Cow::Render(sf::RenderWindow &window){
	if (m_active)
		window.draw(sprite);
}

void Cow::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

int Cow::getDamage(){
	return damage;
}

//sets the entity active or inactive
void Cow::setActiveBool(bool active){
	m_active = active;
}