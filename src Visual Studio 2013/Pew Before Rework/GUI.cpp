//GUI.cpp

#include "GUI.h"


//Background
Background::Background(std::string filepath)
{
	bgTex.loadFromFile(filepath);
	bgTex.setSmooth(false);
	bgSprite.setTexture(bgTex);
	bgSprite.setPosition(0, 0);
}

void Background::Render(sf::RenderWindow &window)
{
	window.draw(bgSprite);
}

//movable Background
MovableBackground::MovableBackground(std::string filepath, sf::RenderWindow &window)
{
	mbgTex.loadFromFile(filepath);
	mbgTex.setSmooth(false);
	mbgTex.setRepeated(true);
	mbgSprite.setTexture(mbgTex);
	mbgSprite.setPosition(0, 0);
	bgY = 0;
	mbgSprite.setTextureRect(sf::IntRect(0, bgY, window.getSize().x, window.getSize().y));

}

void MovableBackground::Update(sf::RenderWindow &window, float &elapsedTime, float &speed, bool &direction)
{
	//direction true for down, false for up

	if (bgY < window.getSize().y)
	{
		if (direction == 1)
		{
			bgY -= speed * elapsedTime;
		}
		else
		{
			bgY += speed * elapsedTime;
		}
	}
	else
	{
		bgY = 0;
	}
	mbgSprite.setTextureRect(sf::IntRect(0, bgY, window.getSize().x, window.getSize().y));
}

void MovableBackground::Render(sf::RenderWindow &window)
{
	window.draw(mbgSprite);
}

float MovableBackground::getY()
{
	return mbgSprite.getPosition().y;
}

//Text
Text::Text(int size)
{
	font.loadFromFile("graphics/font/Saddlebag.ttf");
	text.setFont(font);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(size);
}

Text::Text(std::string output, int size)
{
	font.loadFromFile("graphics/font/Saddlebag.ttf");
	text.setFont(font);
	text.setString(output);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(size);
}

void Text::setColor(sf::Color color)
{
	text.setColor(color);
}

void Text::setPosition(float x, float y)
{
	text.setPosition(x, y);
}

void Text::setOrigin(float x, float y)
{
	text.setOrigin(x, y);
}

void Text::Update(std::stringstream &stream, int value)
{
	text.setString(stream.str());
	stream.str("");
	stream << value;
}

void Text::Render(sf::RenderWindow &window)
{
	window.draw(text);
}

sf::FloatRect Text::getGlobalBounds()
{
	return text.getGlobalBounds();
}

//health
Health::Health(std::string filepath)
{
	healthTexture.loadFromFile(filepath);
	healthTexture.setSmooth(false);
	healthSprite.setTexture(healthTexture);
}


void Health::setPosition(float x, float y)
{
	healthSprite.setPosition(x, y);
}

void Health::Render(sf::RenderWindow &window)
{
	window.draw(healthSprite);
}

sf::Vector2f Health::getPosition()
{
	return healthSprite.getPosition();
}

//healthbar
Healthbar::Healthbar()
{
	hbTex.loadFromFile("graphics//core//healthbar.jpg");
	hbTex.setSmooth(false);
	hbSprite.setTexture(hbTex);
	hbSprite.setPosition(71.55, 13);

	hbBG.loadFromFile("graphics//core//healthbarBG.jpg");
	hbBG.setSmooth(false);
	hbBGSprite.setTexture(hbBG);
	hbBGSprite.setPosition(70, 13);
}

void Healthbar::Update(sf::RenderWindow &window, int health)
{
	if (health <= 100)
	{
		health = 100 - health;
		hbSprite.setPosition(71.55 - health * 1.55, 13);
	}

}

void Healthbar::RenderBG(sf::RenderWindow &window)
{
	window.draw(hbBGSprite);
}

void Healthbar::Render(sf::RenderWindow &window)
{
	window.draw(hbSprite);
}

//CircleShape
GUIcircleShape::GUIcircleShape()
{
	speed = 0.02;
	texture.loadFromFile("graphics//pewcd.png");
	texture.setSmooth(false);
	shape.setRadius(25);
	shape.setPosition(450, 0);
	texY = 0;
	shape.setTexture(&texture);
	shape.setTextureRect(sf::IntRect(450, texY, 53, 50));

}

void GUIcircleShape::Update(bool &pewOnCooldown, float &elapsedTime)
{
	if (pewOnCooldown)
	{
		if (texY > -50)
		{
			texY -= speed * elapsedTime;
		}
		else
		{
			texY = 0;
			pewOnCooldown = false;

		}
		shape.setTextureRect(sf::IntRect(450, texY, 53, 50));
	}
}

void GUIcircleShape::Render(sf::RenderWindow &window)
{
	window.draw(shape);
}