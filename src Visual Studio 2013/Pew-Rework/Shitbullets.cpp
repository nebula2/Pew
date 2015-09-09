//ShitBullets.cpp

#include "ShitBullets.h"

sf::Texture ShitBullets::shitTex;

ShitBullets::ShitBullets(){
	speed = 0.2;
	IOsmooth smooth;
	active = true;
	hasTargetTexture = false;
	shitTex.loadFromFile("graphics//enemies//shit.png");
	shitTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(shitTex);
	sprite.setOrigin(17.5, 17.5);
}

void ShitBullets::Update(sf::RenderWindow &window, float elapsedTime){
	if (active)	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y <= window.getSize().y)
			y += speed*elapsedTime;
		
		else
			active = false;

		sprite.setPosition(x, y);
	}
}

void ShitBullets::Render(sf::RenderWindow &window){
	if (active)

		//check for mouseOver
	if (sprite.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
		if (!hasTargetTexture){
			shitTex.loadFromFile("graphics//enemies//shit_target.png");
			sprite.setTexture(shitTex);
			hasTargetTexture = true;
		}
	}
	else{
		if (hasTargetTexture){
			shitTex.loadFromFile("graphics//enemies//shit.png");
			sprite.setTexture(shitTex);
			hasTargetTexture = false;
		}
	}

		window.draw(sprite);
}

void ShitBullets::SetPosition(float x, float y){
	sprite.setPosition(x, y);
}

int ShitBullets::getDamage(){
	IOdiff diff;
	return 10 * diff.ReadDiffSettings();
}
