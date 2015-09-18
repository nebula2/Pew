//Bullet.h

#ifndef _BULLET_H
#define _BULLET_H

#include <SFML/Graphics.hpp>


class Bullet{
public:
	Bullet(float playerPosX, float playerPosY, sf::RenderWindow& window);

	void Update(float elapsedTime);
	void Render(sf::RenderWindow &window);
	void setActiveBool(bool active);

	void SetPosition(float x, float y);
	bool getActiveBool() const { return m_active; }
	bool getIsPew() const { return m_isPew; }

	int getDamage();
	
	sf::Sprite sprite;
private:
	float speed;
	static sf::Texture bulletTex;
	float dirX;
	float dirY;
	float dir;
	bool m_active;			///< if this is true-> it is active
	bool m_isPew;
	sf::Vector2f _direction;
	sf::Vector2f normalize(sf::Vector2f& source);

};
#endif