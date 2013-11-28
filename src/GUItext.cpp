#include "GUItext.h"

GUItext::GUItext(int size)
{
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(size);
}

GUItext::GUItext(std::string string, int size)
{
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setString(string);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(size);
}

void GUItext::setColor(sf::Color color)
{
	text.setColor(color);
}

void GUItext::setPosition(float x, float y)
{
	text.setPosition(x, y);
}

void GUItext::Update(std::stringstream &stream, int value)
{
	text.setString(stream.str());
	stream.str("");
	stream << value;
}

void GUItext::Render(sf::RenderWindow &window)
{
	window.draw(text);
}

sf::FloatRect GUItext::getGlobalBoundz()
{
	return text.getGlobalBounds();
}