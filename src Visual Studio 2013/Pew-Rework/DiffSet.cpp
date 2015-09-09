//DiffSet.cpp

#include "DiffSet.h"

DiffSet::DiffSet(){
	//basic stuff
	selection = diff.ReadDiffSettings();
	bg.setFilePath("graphics//core//settings.jpg");

	//Sound
	iosound.ReadSoundSettings(volume);
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	//buttons
	easy.setStringAndSize("easy", 70);
	normal.setStringAndSize("normal", 70);
	crazy.setStringAndSize("crazy", 70);
	info.setStringAndSize("enter = save, esc = back", 40);

	easy.setPosition(270, 150);
	normal.setPosition(270, 250);
	crazy.setPosition(270, 350);
	info.setPosition(50, 500);
	info.setColor(sf::Color(255, 128, 0));
}
DiffSet::~DiffSet(){
}

void DiffSet::HandleEvents(Game &game){
	sf::Event pEvent;
	while (game.window.pollEvent(pEvent))	{
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		//keyboard selection
		if (pEvent.type == sf::Event::KeyPressed){
			switch (pEvent.key.code){
			case sf::Keyboard::Up:
				if (selection > 1){
					selection -= 1;
					sound.PlaySound("select");
				}
				else
					selection = 1;
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
				diff.WriteDiffSettings(selection);
				game.ChangeState(Game::gameStates::SETTINGS);
				break;
			case sf::Keyboard::Escape:
				game.ChangeState(Game::gameStates::SETTINGS);
				break;
			default:
				break;
			}
		}
	}
}
void DiffSet::Update(Game &game){

	//do crazy mouse stuff !!!BOOJAH!!! #21. Century
	//play
	if (easy.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(game.window).x, sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f))){
		if (selection != 1){
			selection = 1;
			sound.PlaySound("select");
		}
	}

	//again
	if (normal.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(game.window).x, sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f))){
		if (selection != 2){
			selection = 2;
			sound.PlaySound("select");
		}
	}
	//settings
	if (crazy.getGlobalBounds().intersects(sf::Rect<float>(sf::Mouse::getPosition(game.window).x, sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f))){
		if (selection != 3){
			selection = 3;
			sound.PlaySound("select");
		}
	}

	//change the color depending on selection
	if (selection == 1){//easy
		easy.setColor(sf::Color(255, 128, 0));
		normal.setColor(sf::Color(255, 255, 255));
		crazy.setColor(sf::Color(255, 255, 255));
	}
	else if (selection == 2){//normal
		easy.setColor(sf::Color(255, 255, 255));
		normal.setColor(sf::Color(255, 128, 0));
		crazy.setColor(sf::Color(255, 255, 255));
	}
	else{ //crazy
		easy.setColor(sf::Color(255, 255, 255));
		normal.setColor(sf::Color(255, 255, 255));
		crazy.setColor(sf::Color(255, 128, 0));
	}
}
void DiffSet::Render(Game &game){
	bg.Render(game.window);
	easy.Render(game.window);
	normal.Render(game.window);
	crazy.Render(game.window);
	info.Render(game.window);
}