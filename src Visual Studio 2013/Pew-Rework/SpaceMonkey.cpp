//ShitMonkey.cpp

#include "SpaceMonkey.h"

sf::Texture SpaceMonkey::enemyTex;

SpaceMonkey::SpaceMonkey(){
	IOdiff diff;
	IOsmooth smooth;
	hasTargetTexture = false;
	speed = 0.3;
	health = 10 * diff.ReadDiffSettings();
	active = true;
	moveLeft = true;

	enemyTex.loadFromFile("graphics//enemies//spacemonkey.png");
	enemyTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(enemyTex);
	sprite.setOrigin(36, 20);
	sprite.setPosition(364, 25);

}
void SpaceMonkey::Update(sf::RenderWindow &window, float elapsedTime){
	float x = sprite.getPosition().x;
	float y = sprite.getPosition().y;

	if (SpaceMonkey::active)	{
		if (y <= 80)
			y += speed*elapsedTime;
		
		if (moveLeft && x > 36)
			x -= speed*elapsedTime;
		
		else
			moveLeft = false;
		

		if (!moveLeft && x < window.getSize().x - 36)
			x += speed*elapsedTime;
		
		else
			moveLeft = true;
	}
	sprite.setPosition(x, y);
}


void SpaceMonkey::Render(sf::RenderWindow &window){
	if (active)

		//check for mouseOver
	if (sprite.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
		if (!hasTargetTexture){
			enemyTex.loadFromFile("graphics//enemies//spacemonkey_target.png");
			sprite.setTexture(enemyTex);
			hasTargetTexture = true;
		}
	}
	else{
		if (hasTargetTexture){
			enemyTex.loadFromFile("graphics//enemies//spacemonkey.png");
			sprite.setTexture(enemyTex);
			hasTargetTexture = false;
		}
	}

		window.draw(sprite);
}

void SpaceMonkey::SetPosition(float x, float y){
	sprite.setPosition(x, y);
}

void SpaceMonkey::reduceHealth(int pDamage){
	int newhealth = health - pDamage;
	health = newhealth;
}

int SpaceMonkey::getHealth(){
	return health;
}

sf::Vector2f SpaceMonkey::getPosition(){
	return sprite.getPosition();
}
int SpaceMonkey::getDamage(){
	return 20;
}