//EnemyFormation.h

#include "EnemyFormation.h"

sf::Texture EnemyFormation::texture;

EnemyFormation::EnemyFormation(){
	IOdiff diff;
	IOsmooth smooth;
	speed = 0.6f;
	damage = 15;
	active = true;
	health = 3 * diff.ReadDiffSettings();
	hasTargetTexture = false;
	texture.loadFromFile("graphics/enemies/enemyFormation.png");
	texture.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(texture);
}
void EnemyFormation::Update(sf::RenderWindow &window, float elapsedTime){
	float x = sprite.getPosition().x;
	float y = sprite.getPosition().y;

	if (y <= window.getSize().y)	{
		if (y <= window.getSize().y / 3)
			y += (speed / 3) * elapsedTime;

		else
			y += speed * elapsedTime;
	}
	else
		active = false;
	
		sprite.setPosition(x, y);
}
void EnemyFormation::Render(sf::RenderWindow &window){
	//check for mouseOver
	if (sprite.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
		if (!hasTargetTexture){
			texture.loadFromFile("graphics/enemies/enemyFormation_target.png");
			sprite.setTexture(texture);
			hasTargetTexture = true;
		}
	}
	else{
		if (hasTargetTexture){
			texture.loadFromFile("graphics/enemies/enemyFormation.png");
			sprite.setTexture(texture);
			hasTargetTexture = false;
		}
	}

	window.draw(sprite);
}

void EnemyFormation::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

void EnemyFormation::reduceHealth(int pDamage){
	int newhealth = health - pDamage;
	health = newhealth;
}

int EnemyFormation::getHealth(){
	return health;
}

int EnemyFormation::getDamage(){
	return damage;
}

