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
	void setActiveBool(bool active);

	int getDamage() const { return 1; };
	bool getActiveBool() const { return m_active; }
	bool getIsPew() const { return m_isPew; }

	sf::Sprite sprite;
private:
	sf::Vector2f normalize(sf::Vector2f& source);

	static sf::Texture m_doubleTex;
	float dirX;
	float dirY;
	float dir;
	sf::Vector2f m_direction;
	bool m_active;			///< if this is true-> it is active
	bool m_isPew;
};
#endif