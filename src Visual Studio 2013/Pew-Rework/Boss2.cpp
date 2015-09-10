//Boss2.cpp

#include "Boss2.h"
#include <cmath>
#define PI 3.14159265

sf::Texture Boss2::enemyTex;

Boss2::Boss2(){
	IOdiff diff;
	IOsmooth smooth;
	hasTargetTexture = false;
	speed = 0.5;
	health = 200 * diff.ReadDiffSettings();
	active = true;
	fadeIn = false;
	moveLeft = true;
	sinValue = 0;
	debauch = 30;

	enemyTex.loadFromFile("graphics/enemies/boss2.png");
	enemyTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(enemyTex);
	sprite.setOrigin(75, 105.5);
}

void Boss2::Update(sf::RenderWindow &window, float elapsedTime){
	float x = sprite.getPosition().x;
	float y = sprite.getPosition().y;

	sinValue += elapsedTime;

	//handle movement
	if (Boss2::active){
		//slow fade in
		if (!fadeIn)
			y += speed * elapsedTime / 4; 

		//if enemy is completely on screen
		if (y >= 175)
			fadeIn = true;

		//handle x movement
		if (moveLeft && x > 75)
			x -= speed * elapsedTime;
	
		else 
			moveLeft = false;
		
		if (!moveLeft && x < window.getSize().x - 75)
			x += speed * elapsedTime;
		
		else 
			moveLeft = true;

		//handle y movement (just a thought atm)
		if (fadeIn){
			y = 175 + (float)std::sin(sinValue * PI / 180) * debauch;
			
			if (sinValue > 360) //is the value that gets higher to get the curve effect
				sinValue = 0;
		}

		//set new coordinates
		sprite.setPosition(x, y);
	}
}

void Boss2::Render(sf::RenderWindow &window){
	//check for mouseOver
	if (sprite.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
		if (!hasTargetTexture){
			enemyTex.loadFromFile("graphics/enemies/boss2_target.png");
			sprite.setTexture(enemyTex);
			hasTargetTexture = true;
		}
	}
	else{
		if (hasTargetTexture){
			enemyTex.loadFromFile("graphics/enemies/boss2.png");
			sprite.setTexture(enemyTex);
			hasTargetTexture = false;
		}
	}

	window.draw(sprite);
}

void Boss2::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

void Boss2::reduceHealth(int pDamage){
	int newhealth = health - pDamage;
	health = newhealth;
}

int Boss2::getHealth(){
	return health;
}

int Boss2::getDamage(){
	return 30;
}

bool Boss2::getfadeIn(){
	return fadeIn;
}

sf::Vector2f Boss2::getPosition(){
	return sprite.getPosition();
}