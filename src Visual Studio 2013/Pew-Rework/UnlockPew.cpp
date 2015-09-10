//UnlockPew.cpp

#include "UnlockPew.h"

sf::Texture UnlockPew::pewDropTex;

UnlockPew::UnlockPew(){
	speed = 0.1;
	active = true;

	pewDropTex.loadFromFile("graphics/pewDrop.png");

	pewDropTex.setSmooth(false);
	pewDropSprite.setTexture(pewDropTex);
	pewDropSprite.setOrigin(17.5, 17.5);
	pewDropSprite.setPosition(400, 50);
}

void UnlockPew::Update(sf::RenderWindow &window, float elapsedTime){
	if (UnlockPew::active){
		float x = pewDropSprite.getPosition().x;
		float y = pewDropSprite.getPosition().y;

		if (y <= window.getSize().y / 2)
			y += speed*elapsedTime;
		
		else if (y >= window.getSize().y / 2)
			y = window.getSize().y / 2;

		x = window.getSize().x / 2;

		pewDropSprite.setPosition(x, y);
	}
}

void UnlockPew::Render(sf::RenderWindow &window){
	if (active)
		window.draw(pewDropSprite);
}

void UnlockPew::SetPosition(float x, float y){
	pewDropSprite.setPosition(x, y);
}