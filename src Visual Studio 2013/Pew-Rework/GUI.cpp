//GUI.cpp

#include "GUI.h"


//Background
Background::Background(){
	bgTex.setSmooth(false);
	bgSprite.setPosition(0, 0);
}

void Background::setFilePath(std::string filepath){
	bgTex.loadFromFile(filepath);
	bgSprite.setTexture(bgTex);
}

void Background::Render(sf::RenderWindow &window){
	window.draw(bgSprite);
}

//movable Background
MovableBackground::MovableBackground(){
	mbgTex.setSmooth(false);
	mbgTex.setRepeated(true);
	mbgSprite.setTexture(mbgTex);
	mbgSprite.setPosition(0, 0);
	bgY = 0;
}

void MovableBackground::setStuff(std::string filepath, sf::Vector2f windowSize){
	mbgTex.loadFromFile(filepath);
	mbgSprite.setTexture(mbgTex);
	mbgSprite.setTextureRect(sf::IntRect(0, (int)bgY, (int)windowSize.x, (int)windowSize.y));
}
void MovableBackground::Update(sf::RenderWindow &window, float &elapsedTime, float &speed){
	if (bgY < window.getSize().y)
		bgY -= speed * elapsedTime;
	else
	{
		bgY = 0;
	}
	mbgSprite.setTextureRect(sf::IntRect(0, (int)bgY, (int)window.getSize().x, (int)window.getSize().y));
}

void MovableBackground::Render(sf::RenderWindow &window){
	window.draw(mbgSprite);
}

float MovableBackground::getY(){
	return mbgSprite.getPosition().y;
}

//Text
Text::Text(){
	font.loadFromFile("graphics/font/Saddlebag.ttf");
	text.setFont(font);
	text.setStyle(sf::Text::Bold);
}

void Text::setSize(int size){
	text.setCharacterSize(size);
}

void Text::setStringAndSize(std::string output, int size){
	text.setString(output);
	text.setCharacterSize(size);
}

void Text::setColor(sf::Color color){
	text.setColor(color);
}

void Text::setPosition(float x, float y){
	text.setPosition(x, y);
}

void Text::setOrigin(float x, float y){
	text.setOrigin(x, y);
}

void Text::Update(std::stringstream &stream, int value){
	text.setString(stream.str());
	stream.str("");
	stream << value;
}

void Text::Render(sf::RenderWindow &window){
	window.draw(text);
}

sf::FloatRect Text::getGlobalBounds(){
	return text.getGlobalBounds();
}

//health
Health::Health(){
	healthTexture.setSmooth(false);
	healthTexture.loadFromFile("graphics/health.png");
	healthSprite.setTexture(healthTexture);
}

void Health::setPosition(float x, float y){
	healthSprite.setPosition(x, y);
}

void Health::Render(sf::RenderWindow &window){
	window.draw(healthSprite);
}

sf::Vector2f Health::getPosition(){
	return healthSprite.getPosition();
}

//healthbar
Healthbar::Healthbar(){
	hbTex.loadFromFile("graphics/core/healthbar.jpg");
	hbTex.setSmooth(false);
	hbSprite.setTexture(hbTex);
	hbSprite.setPosition(71.55f, 13.0f);
	hbSprite.setTextureRect(sf::IntRect(71, 13, 155, 25));
}

void Healthbar::Update(sf::RenderWindow &window, int health){
	if (health <= 100)
	{
		health = 100 - health;
		hbSprite.setTextureRect(sf::IntRect(72, 13, (int)(155 - health * 1.55), 25));
	}
}

void Healthbar::Render(sf::RenderWindow &window){
	window.draw(hbSprite);
}

//CircleShape
GUIcircleShape::GUIcircleShape(){
	speed = 0.02f;
	texY = 0.0f;

	if (!texture.loadFromFile("graphics/pewcd.png"))
		std::cout << "could not load cooldown-Texture \"pewcd.png\" \n";
	texture.setSmooth(false);
	
	shape.setRadius(25);
	shape.setPosition(450, 0);
	shape.setTexture(&texture);
	shape.setTextureRect(sf::IntRect(450, (int)texY, 53, 50));
}

void GUIcircleShape::Update(bool &pewOnCooldown, float &elapsedTime){
	if (pewOnCooldown){
		if (texY > -50)
			texY -= speed * elapsedTime;

		else{
			texY = 0;
			pewOnCooldown = false;
		}

		shape.setTextureRect(sf::IntRect(450, (int)texY, 53, 50));
	}
}

void GUIcircleShape::Render(sf::RenderWindow &window){
	window.draw(shape);
}