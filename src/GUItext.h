#ifndef GUITEXT_H
#define GUITEXT_H

#include <string>
#include <SFML\Graphics.hpp>
#include <sstream>

class GUItext
{
public:

	GUItext(int size);
	GUItext(std::string string, int size);
	void setColor(sf::Color color);
	void setPosition(float x, float y);
	void Update(std::stringstream &stream, int value);
	void Render(sf::RenderWindow &window);
	sf::FloatRect getGlobalBoundz();

private:
	sf::Text text;
	sf::Font font;
};
#endif