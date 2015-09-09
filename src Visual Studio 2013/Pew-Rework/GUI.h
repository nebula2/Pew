//GUI.h

#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>

//static background
class Background{
public:
	Background();
	void setFilePath(std::string filepath);
	void Render(sf::RenderWindow &window);
private:
	sf::Texture bgTex;
	sf::Sprite  bgSprite;
};

//movable background
class MovableBackground{
public:
	MovableBackground();
	void setStuff(std::string filepath, sf::Vector2f windowSize);
	void Update(sf::RenderWindow &window, float &elapsedTime, float &speed);
	void Render(sf::RenderWindow &window);
	float getY();
private:
	sf::Texture mbgTex;
	sf::Sprite mbgSprite;
	float bgSpeed;
	float bgY;
};

//Text to show on screen
class Text{
public:
	Text();
	void setSize(int size);
	void setStringAndSize(std::string output, int size);
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

//Health
class Health{
public:
	Health();
	void setFilePath(std::string filepath);
	void setPosition(float x, float y);
	void Render(sf::RenderWindow &window);
	sf::Vector2f getPosition();
private:
	sf::Texture healthTexture;
	sf::Sprite healthSprite;
};

//Healthbar
class Healthbar{
public:
	Healthbar();
	void Update(sf::RenderWindow &window, int health);
	void Render(sf::RenderWindow &window);
private:
	sf::Texture hbTex;
	sf::Sprite	hbSprite;
};

//circleShape (currently used for showing PewCooldown
class GUIcircleShape{
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