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
	void setActiveBool(bool active);
	bool getIsPew() const { return m_isPew; }

	int getDamage();
	bool getActiveBool() const { return m_active; }

	sf::Sprite sprite;
private:
	float speed;
	static sf::Texture pewShotTex;
	float dirX;
	float dirY;
	float dir;
	sf::Vector2f _direction;
	sf::Vector2f normalize(sf::Vector2f& source);
	bool m_active;			///< if this is true-> it is active
	bool m_isPew;
};
#endif