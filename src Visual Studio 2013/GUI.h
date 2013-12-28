//GUI.h

#ifndef GUI_H
#define GUI_H

//you need SMFL
#include <SFML\Graphics.hpp>
#include <string>
#include <sstream>

namespace GUI
{
}

class Background
{
public:
	Background(std::string filepath);
	void Render(sf::RenderWindow &window);
private:
	sf::Texture bgTex;
	sf::Sprite  bgSprite;
};

class MovableBackground
{
public:
	MovableBackground(std::string filepath, sf::RenderWindow &window);
	void Update(sf::RenderWindow &window, float &elapsedTime, float &speed, bool &direction);
	void Render(sf::RenderWindow &window);
	float getY();
private:
	sf::Texture mbgTex;
	sf::Sprite mbgSprite;
	float bgSpeed;
	float bgY;
};

class Text
{
public:
	Text(int size);
	Text(std::string output, int size);
	void setColor(sf::Color color);
	void setPosition(float x, float y);
	void setOrigin(float x, float y);
	void Update(std::stringstream &stream, int value);
	void Render(sf::RenderWindow &window);
	sf::FloatRect getGlobalBounds();
private:
	sf::Text text;
	sf::Font font;
};

class Health
{
public:
	Health(std::string filepath);
	void setPosition(float x, float y);
	void Render(sf::RenderWindow &window);
	sf::Vector2f getPosition();
private:
	sf::Texture healthTexture;
	sf::Sprite healthSprite;
};

class Healthbar
{
public:
	Healthbar();
	void Update(sf::RenderWindow &window, int health);
	void RenderBG(sf::RenderWindow &window);
	void Render(sf::RenderWindow &window);
private:
	sf::Texture hbTex;
	sf::Texture hbBG;
	sf::Sprite	hbSprite;
	sf::Sprite	hbBGSprite;
};

class GUIcircleShape
{
public:
	GUIcircleShape();
	void Update(bool &pewOnCooldown, float &elapsedTime);
	void Render(sf::RenderWindow &window);
private:
	sf::Texture texture;
	sf::CircleShape shape;
	float speed;
	float texY;
};

#endif