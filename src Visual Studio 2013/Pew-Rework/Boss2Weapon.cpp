//Boss2Weapon.cpp

#include "Boss2Weapon.h"

sf::Texture Boss2Weapon::weaponTex;

Boss2Weapon::Boss2Weapon(){
	IOsmooth smooth;
	speed = 0.3;
	active = true;
	hasTargetTexture = false;
	weaponTex.loadFromFile("graphics/enemies/boss2weapon.png");
	weaponTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(weaponTex);
	sprite.setOrigin(22, 25);
}

void Boss2Weapon::Update(sf::RenderWindow &window, float &elapsedTime, Player &pPlayer, Player2 &player2){
	if (active)	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		//move down
		if (y <= window.getSize().y)
			y += speed * elapsedTime;
		
		else
			active = false;

		//track player
		if (pPlayer.active)		{
			if (x < pPlayer.getPosition().x)
				x += speed * elapsedTime;
			
			if (x > pPlayer.getPosition().x)
				x -= speed * elapsedTime;
			
		}
		if (!pPlayer.active && player2.active){
			if (x < player2.getPosition().x)
				x += speed * elapsedTime;
			
			if (x > player2.getPosition().x)
				x -= speed * elapsedTime;
		}

		sprite.setPosition(x, y);
	}
}

void Boss2Weapon::Render(sf::RenderWindow &window)
{
	if (active)
		//check for mouseOver
	if (sprite.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
		if (!hasTargetTexture){
			weaponTex.loadFromFile("graphics/enemies/boss2weapon_target.png");
			sprite.setTexture(weaponTex);
			hasTargetTexture = true;
		}
	}
	else{
		if (hasTargetTexture){
			weaponTex.loadFromFile("graphics/enemies/boss2weapon.png");
			sprite.setTexture(weaponTex);
			hasTargetTexture = false;
		}
	}
		window.draw(sprite);
}

void Boss2Weapon::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

int Boss2Weapon::getDamage(){
	IOdiff diff;
	return 15 * diff.ReadDiffSettings();
}