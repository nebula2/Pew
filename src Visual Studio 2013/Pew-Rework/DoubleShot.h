//DoubleShot.h

#ifndef DOUBLESHOT_H
#define DOUBLESHOT_H

#include <SFML/Graphics.hpp>

class DoubleShot{
public:
	DoubleShot(float playerPosX, float playerPosY, sf::RenderWindow& window);
	void Update(float elapsedTime);
	void Render(sf::RenderWindow &window);
	void SetPosition(float x, float y);
	int getDamage() const { return 1; };
	bool isPew;
	bool active;
	sf::Sprite sprite;
private:
	sf::Vector2f normalize(sf::Vector2f& source);

	static sf::Texture m_doubleTex;
	float dirX;
	float dirY;
	float dir;
	sf::Vector2f m_direction;
};
#endif