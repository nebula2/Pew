//DoubleShot.cpp

#include "DoubleShot.h"

sf::Texture DoubleShot::doubleTex;

DoubleShot::DoubleShot(float playerPosX, float playerPosY, sf::RenderWindow& window){
	speed = 0.9;
	active = true;
	isPew = false;

	//set direction up
	dirX = sf::Mouse::getPosition(window).x - playerPosX;
	dirY = sf::Mouse::getPosition(window).y - playerPosY;
	dir = sqrt((dirX*dirX) + (dirY*dirY));

	//get direction vector and normalize it
	_direction.x = sf::Mouse::getPosition(window).x - playerPosX;
	_direction.y = sf::Mouse::getPosition(window).y - playerPosY;
	_direction = normalize(_direction);


	doubleTex.loadFromFile("graphics/weapons/double.png");

	doubleTex.setSmooth(false);
	sprite.setTexture(doubleTex);
}

void DoubleShot::Update(float elapsedTime){
	if (active){
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		sprite.move(_direction * elapsedTime);
		if (y < 0 || y > 900 || x < 0 || x > 900){
			active = false;
		}
	}

}

void DoubleShot::Render(sf::RenderWindow &window){
	if (active)
		window.draw(sprite);
}

void DoubleShot::SetPosition(float x, float y){
	sprite.setPosition(x, y);
}

int DoubleShot::getDamage(){
	return 1;
}

sf::Vector2f DoubleShot::normalize(sf::Vector2f& source){
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0.0f){
		return sf::Vector2f(source.x / length, source.y / length);
	}
	else
		return source;
}