//Pew.cpp

#include "Pew.h"

sf::Texture Pew::pewShotTex;

Pew::Pew(float playerPosX, float playerPosY, sf::RenderWindow& window){
	speed = 0.9;
	active = true;
	isPew = true;

	//set direction up
	dirX = sf::Mouse::getPosition(window).x - playerPosX;
	dirY = sf::Mouse::getPosition(window).y - playerPosY;
	dir = sqrt((dirX*dirX) + (dirY*dirY));

	//get direction vector and normalize it
	_direction.x = sf::Mouse::getPosition(window).x - playerPosX;
	_direction.y = sf::Mouse::getPosition(window).y - playerPosY;
	_direction = normalize(_direction);

	pewShotTex.loadFromFile("graphics/weapons/pew.png");

	pewShotTex.setSmooth(false);
	sprite.setTexture(pewShotTex);
}

void Pew::Update(float elapsedTime){
	if (active){
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		sprite.move(_direction * elapsedTime);
		if (y < 0 || y > 900 || x < 0 || x > 900){
			active = false;
		}
	}

}

void Pew::Render(sf::RenderWindow &window){
	if (active)
		window.draw(sprite);
}

void Pew::SetPosition(float x, float y){
	sprite.setPosition(x, y);
}

int Pew::getDamage(){
	return 20;
}

sf::Vector2f Pew::normalize(sf::Vector2f& source){
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0.0f){
		return sf::Vector2f(source.x / length, source.y / length);
	}
	else
		return source;
}