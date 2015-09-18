//Cow.h

#ifndef COW_H
#define COW_H

#include <SFML/Graphics.hpp>
#include "IOstuff.h"

class Cow{
public:
	Cow();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);

	//setter
	void setPosition(float x, float y);
	void setActiveBool(bool active);

	//getter
	int getDamage();
	bool getActiveBool() const { return m_active; }

	sf::Sprite sprite;
private:
	float speed;
	static sf::Texture cowTex;
	int damage;
	bool hasTargetTexture;
	bool m_active;			///< if this is true-> it is active
};

#endif