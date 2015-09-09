//Boss3SecWeapon.cpp

#include "Boss3SecWeapon.h"


sf::Texture Boss3SecWeapon::weaponTex;

Boss3SecWeapon::Boss3SecWeapon(){
	IOsmooth smooth;
	speed = 0.5;
	active = true;
	health = 3;
	hasTargetTexture = false;
	weaponTex.loadFromFile("graphics//enemies//smallCow.png");
	weaponTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(weaponTex);
	sprite.setOrigin(23.5, 12);
}

void Boss3SecWeapon::Update(sf::RenderWindow &window, float &elapsedTime){
	if (active){
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y <= window.getSize().y)
			y += speed*elapsedTime;
		
		else
			active = false;
		
		sprite.setPosition(x, y);
	}
}

void Boss3SecWeapon::Render(sf::RenderWindow &window){
	if (active)

		//check for mouseOver
	if (sprite.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
		if (!hasTargetTexture){
			weaponTex.loadFromFile("raphics//enemies//smallCow_target.png");
			sprite.setTexture(weaponTex);
			hasTargetTexture = true;
		}
	}
	else{
		if (hasTargetTexture){
			weaponTex.loadFromFile("raphics//enemies//smallCow.png");
			sprite.setTexture(weaponTex);
			hasTargetTexture = false;
		}
	}

		window.draw(sprite);
}

void Boss3SecWeapon::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

int Boss3SecWeapon::getDamage(){
	IOdiff diff;
	return 5 * diff.ReadDiffSettings();
}

void Boss3SecWeapon::reduceHealth(int pDamage){
	int newhealth = health - pDamage;
	health = newhealth;
}

int Boss3SecWeapon::getHealth(){
	return health;
}