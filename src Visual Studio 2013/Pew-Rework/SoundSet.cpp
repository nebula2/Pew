//SoundSet.cpp

#include "SoundSet.h"

SoundSet::SoundSet(){
	bg.setFilePath("graphics//core//soundset.jpg");

	selectionString.setSize(50);
	selectionString.setPosition(350, 250);
	selectionString.setColor(sf::Color::White);

	//read actual settings into volume
	iosound.ReadSoundSettings(volume);
	selection = volume;
}
SoundSet::~SoundSet(){
}

void SoundSet::HandleEvents(Game &game){
	sf::Event pEvent;
	while (game.window.pollEvent(pEvent)){
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		if (pEvent.type == sf::Event::KeyPressed){
			switch (pEvent.key.code){
			case sf::Keyboard::Right:
				if (selection < 100)
					selection += 5;

				else
					selection = 100;
				break;
			case sf::Keyboard::Left:
				if (selection > 0)
					selection -= 5;
				break;
			case sf::Keyboard::Escape:
				game.ChangeState(Game::gameStates::SETTINGS);
				break;
			case sf::Keyboard::Return:
				iosound.WriteSoundSettings(selection);
				game.ChangeState(Game::gameStates::SETTINGS);
				break;
			default:
				break;

			}
		}
	}
}
void SoundSet::Update(Game &game){
	selectionString.Update(selectionStream, selection);

	if (selection != game.getVolume())
		game.setVolume(selection);
}
void SoundSet::Render(Game &game){
	bg.Render(game.window);
	selectionString.Render(game.window);
}