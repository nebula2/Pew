//HealthDrop.h

#ifndef HEALTHDROP_H
#define HEALTHDROP_H

#include <SFML/Graphics.hpp>

class HealthDrop{
public:
	HealthDrop();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void SetPosition(float x, float y);
	void setActiveBool(bool active);

	bool getActiveBool() const { return m_active; }

	sf::Sprite healthDropSprite;
private:
	bool m_active;			///< if this is true-> it is active
	float speed;
	static sf::Texture healthDropTex;
};
#endif