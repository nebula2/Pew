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

	sf::Sprite healthDropSprite;
	bool active;
private:
	float speed;
	static sf::Texture healthDropTex;
};
#endif