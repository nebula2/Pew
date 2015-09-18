//UnlockPew.cpp

#include "UnlockPew.h"

sf::Texture UnlockPew::pewDropTex;

UnlockPew::UnlockPew(){
	speed = 0.1f;
	m_active = true;

	pewDropTex.loadFromFile("graphics/pewDrop.png");

	pewDropTex.setSmooth(false);
	pewDropSprite.setTexture(pewDropTex);
	pewDropSprite.setOrigin(17.5, 17.5);
	pewDropSprite.setPosition(400, 50);
}

void UnlockPew::Update(sf::RenderWindow &window, float elapsedTime){
	if (m_active){
		float x = pewDropSprite.getPosition().x;
		float y = pewDropSprite.getPosition().y;

		if (y <= window.getSize().y / 2.0f)
			y += speed*elapsedTime;
		
		else if (y >= window.getSize().y / 2.0f)
			y = window.getSize().y / 2.0f;

		x = window.getSize().x / 2.0f;

		pewDropSprite.setPosition(x, y);
	}
}

void UnlockPew::Render(sf::RenderWindow &window){
	if (m_active)
		window.draw(pewDropSprite);
}

void UnlockPew::SetPosition(float x, float y){
	pewDropSprite.setPosition(x, y);
}

//sets the entity active or inactive
void UnlockPew::setActiveBool(bool active){
	m_active = active;
}