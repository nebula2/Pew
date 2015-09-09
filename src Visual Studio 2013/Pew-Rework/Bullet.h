//Bullet.h

#ifndef _BULLET_H
#define _BULLET_H

#include <SFML/Graphics.hpp>


class Bullet{
public:
	Bullet(float playerPosX, float playerPosY, sf::RenderWindow& window);

	void Update(float elapsedTime);
	void Render(sf::RenderWindow &window);
	void SetPosition(float x, float y);

	int getDamage();
	bool active;
	bool isPew;
	sf::Sprite sprite;
private:
	float speed;
	static sf::Texture bulletTex;
	float dirX;
	float dirY;
	float dir;
	sf::Vector2f _direction;
	sf::Vector2f normalize(sf::Vector2f& source);

};
#endif