//Settings.cpp

#include "Settings.h"


Settings::Settings(){
	//sound
	iosound.ReadSoundSettings(volume);
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	//background
	bg.setFilePath("graphics//core//settings.png");

	//buttons
	difficulty.setStringAndSize("Difficulty", 70);
	graphics.setStringAndSize("Graphics", 70);
	sounds.setStringAndSize("Sound", 70);
	back.setStringAndSize("Back", 70);


	difficulty.setPosition(270, 100);
	sounds.setPosition(270, 200);
	graphics.setPosition(270, 300);
	back.setPosition(270, 400);
}
Settings::~Settings(){
}

void Settings::HandleEvents(Game &game){
	sf::Event pEvent;

	while (game.window.pollEvent(pEvent))	{
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);
		
		//keyboard
		if (pEvent.type == sf::Event::KeyPressed){
			switch (pEvent.key.code){
			case sf::Keyboard::Up:
				if (selection > 0){
					selection -= 1;
					sound.PlaySound("select");
				}
				else
					selection = 0;
				break;
			case sf::Keyboard::Down:
				if (selection < 3){
					selection += 1;
					sound.PlaySound("select");
				}
				else
					selection = 3;
				break;
			case sf::Keyboard::Return:
				if (selection == 0)//diff
					game.ChangeState(Game::gameStates::DIFFSET);
				
				else if (selection == 1)//sound
					game.ChangeState(Game::gameStates::SOUNDSET);
				
				else if (selection == 2)//graphics
					game.ChangeState(Game::gameStates::GRAPHICSET);
				
				else//back
					game.ChangeState(Game::gameStates::MAINMENU);
			default:
				break;
			}
		}
		//mouse selection
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
			switch (selection){
			case 0:
				game.ChangeState(Game::gameStates::DIFFSET);
				break;
			case 1:
				game.ChangeState(Game::gameStates::SOUNDSET);
				break;
			case 2:
				game.ChangeState(Game::gameStates::GRAPHICSET);
				break;
			case 3:
				game.ChangeState(Game::gameStates::MAINMENU);
				break;
			default:
				break;
			}
		}
	}
}

void Settings::Update(Game &game){

	//do crazy mouse stuff !!!BOOJAH!!! #21. Century
	//play
	if (difficulty.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(game.window).x, sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f))){
		if (selection != 0){
			selection = 0;
			sound.PlaySound("select");
		}
	}

	//again
	if (sounds.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(game.window).x, sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f))){
		if (selection != 1){
			selection = 1;
			sound.PlaySound("select");
		}
	}
	//settings
	if (graphics.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(game.window).x, sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f))){
		if (selection != 2){
			selection = 2;
			sound.PlaySound("select");
		}
	}
	//close
	if (back.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(game.window).x, sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f))){
		if (selection != 3){
			selection = 3;
			sound.PlaySound("select");
		}
	}

	//do crazy color shit
	if (selection == 0){//diff
		difficulty.setColor(sf::Color(255, 128, 0));
		graphics.setColor(sf::Color(255, 255, 255));
		sounds.setColor(sf::Color(255, 255, 255));
		back.setColor(sf::Color(255, 255, 255));
	}
	else if (selection == 1){//sound
		difficulty.setColor(sf::Color(255, 255, 255));
		graphics.setColor(sf::Color(255, 255, 255));
		sounds.setColor(sf::Color(255, 128, 0));
		back.setColor(sf::Color(255, 255, 255));
	}
	else if (selection == 2){//Graphics
		difficulty.setColor(sf::Color(255, 255, 255));
		graphics.setColor(sf::Color(255, 128, 0));
		sounds.setColor(sf::Color(255, 255, 255));
		back.setColor(sf::Color(255, 255, 255));
	}
	else{//back
		difficulty.setColor(sf::Color(255, 255, 255));
		graphics.setColor(sf::Color(255, 255, 255));
		sounds.setColor(sf::Color(255, 255, 255));
		back.setColor(sf::Color(255, 128, 0));
	}
}
void Settings::Render(Game &game){
	bg.Render(game.window);
	graphics.Render(game.window);
	difficulty.Render(game.window);
	sounds.Render(game.window);
	back.Render(game.window);
}
