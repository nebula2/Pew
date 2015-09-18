//UnlockPew.h

#ifndef UNLOCK_PEW_H
#define UNLOCK_PEW_H

#include <SFML/Graphics.hpp>

class UnlockPew{
public:
	UnlockPew();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void SetPosition(float x, float y);
	void setActiveBool(bool active);

	bool getActiveBool() const { return m_active; }

	sf::Sprite pewDropSprite;
private:
	bool m_active;			///< if this is true-> it is active
	float speed;
	static sf::Texture pewDropTex;
};
#endif