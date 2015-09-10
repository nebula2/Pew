//Intro.cpp

#include "Intro.h"

Intro::Intro(){
	elapsedTime = 0;

	intro.loadFromFile("graphics/core/intro.jpg");
	intro.setSmooth(false);
	introSprite.setTexture(intro);
	introSprite.setPosition(0, 600);
	bgSpeed = 0.03f;
	y = introSprite.getPosition().y;
}

Intro::~Intro(){
}

void Intro::HandleEvents(Game &game){
	sf::Event pEvent;
	
	while (game.window.pollEvent(pEvent))
	{
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		if (pEvent.type == sf::Event::KeyPressed){
			if (pEvent.key.code == sf::Keyboard::Escape)
				game.setRunning(false);

			if (pEvent.key.code == sf::Keyboard::Return)
				game.ChangeState(Game::gameStates::PLAY);
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
		game.ChangeState(Game::gameStates::PLAY);
	}
}
void Intro::Update(Game &game){
	elapsedTime = (float)pClock.restart().asMilliseconds();
	y -= bgSpeed * elapsedTime;
	introSprite.setPosition(0, y);

	if (y <= -1200)
		game.ChangeState(Game::gameStates::PLAY);
}
void Intro::Render(Game &game){
		game.window.draw(introSprite);
}