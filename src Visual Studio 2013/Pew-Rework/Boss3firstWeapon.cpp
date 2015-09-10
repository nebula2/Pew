//Boss3firstWeapon.cpp

#include "Boss3firstWeapon.h"

sf::Texture Boss3firstWeapon::weaponTex;

Boss3firstWeapon::Boss3firstWeapon(){
	IOsmooth smooth;
	speed = 0.5;
	active = true;
	hasTargetTexture = false;
	weaponTex.loadFromFile("graphics/enemies/cowWeapon.png");
	weaponTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(weaponTex);
	sprite.setRotation(180);
	sprite.setOrigin(23.5, 12);
}

void Boss3firstWeapon::Update(sf::RenderWindow &window, float &elapsedTime){
	if (active)	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y <= window.getSize().y)
			y += speed*elapsedTime;
		
		else
			active = false;

		sprite.setPosition(x, y);
		sprite.rotate(5);
	}
}

void Boss3firstWeapon::Render(sf::RenderWindow &window){
	if (active)

		//check for mouseOver
	if (sprite.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
		if (!hasTargetTexture){
			weaponTex.loadFromFile("graphics/enemies/cowWeapon_target.png");
			sprite.setTexture(weaponTex);
			hasTargetTexture = true;
		}
	}
	else{
		if (hasTargetTexture){
			weaponTex.loadFromFile("graphics/enemies/cowWeapon.png");
			sprite.setTexture(weaponTex);
			hasTargetTexture = false;
		}
	}

		window.draw(sprite);
}

void Boss3firstWeapon::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

int Boss3firstWeapon::getDamage(){
	IOdiff diff;
	return 5 * diff.ReadDiffSettings();
}