//UnlockPew.h

#ifndef UNLOCK_PEW_H
#define UNLOCK_PEW_H

#include <SFML/Graphics.hpp>

class UnlockPew
{
public:
	UnlockPew();
	void Update(sf::RenderWindow &Window, float elapsedTime);
	void Render(sf::RenderWindow &Window);
	void SetPosition(float x, float y);

	sf::Sprite pewDropSprite;
	bool active;
private:
	float speed;
	static sf::Texture pewDropTex;
};
#endif