//Enemy.cpp

#include "Enemy.h"

sf::Texture Enemy::enemyTex;

Enemy::Enemy(){
	hasTargetTexture = false;
	IOdiff diff;
	IOsmooth smooth;
	speed = 0.6;
	active = true;
	health = 2 * diff.ReadDiffSettings();

	enemyTex.loadFromFile("graphics//enemies//enemy.png");
	enemyTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(enemyTex);
	sprite.setOrigin(36.5, 35);
}

void Enemy::Update(sf::RenderWindow &window, float elapsedTime, HighscoreManager &highscore){
	if (Enemy::active)	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y <= window.getSize().y)		{
			if (y <= window.getSize().y / 3)
				y += (speed / 3) * elapsedTime;
		
			else
				y += speed * elapsedTime;
		}
		else{
			active = false;
			highscore.setEnemyMissed(1);
		}

		sprite.setPosition(x, y);
		_elapsedTime = elapsedTime;
	}
}

void Enemy::Render(sf::RenderWindow &window){
	if (active){

		//sort dafür, dass das teil richtig behindert gespawned wird :'D
		if (rotation < 360){
			rotation /= _elapsedTime;
			sprite.rotate(rotation);
		}
		else{
			rotation = 0;
		}

		//check for mouseOver
		if (sprite.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
			if (!hasTargetTexture){
				enemyTex.loadFromFile("graphics//enemies//enemy_target.png");
				sprite.setTexture(enemyTex);
				hasTargetTexture = true;
			}
		}
		else{
			if (hasTargetTexture){
				enemyTex.loadFromFile("graphics//enemies//enemy.png");
				sprite.setTexture(enemyTex);
				hasTargetTexture = false;
			}
		}


		window.draw(sprite);
	}
}

void Enemy::SetPosition(float x, float y){
	sprite.setPosition(x, y);
}

void Enemy::reduceHealth(int pDamage){
	int newhealth = health - pDamage;
	health = newhealth;
}

int  Enemy::getHealth(){
	return health;
}

int Enemy::getDamage(){
	return 10;
}
