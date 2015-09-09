//Pew.h

#ifndef PEW_H
#define PEW_H

#include <SFML/Graphics.hpp>

class Pew{
public:
	Pew(float playerPosX, float playerPosY, sf::RenderWindow& window);

	void Update(float elapsedTime);
	void Render(sf::RenderWindow &window);
	void SetPosition(float x, float y);

	int getDamage();


	bool isPew;
	bool active;
	sf::Sprite sprite;
private:
	float speed;
	static sf::Texture pewShotTex;
	float dirX;
	float dirY;
	float dir;
	sf::Vector2f _direction;
	sf::Vector2f normalize(sf::Vector2f& source);
};
#endif