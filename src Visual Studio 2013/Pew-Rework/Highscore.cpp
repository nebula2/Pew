//Highscore.cpp

#include "Highscore.h"


Highscore::Highscore(){
	highscoreWritten = false;

	bg.setFilePath("graphics/core/lose.jpg");

	pointText.setSize(20);
	pointText.setPosition(300, 195);

	eMissedText.setSize(20);
	eMissedText.setPosition(300, 255);

	eKilledText.setSize(20);
	eKilledText.setPosition(300, 317);

	mKilledText.setSize(20);
	mKilledText.setPosition(300, 380);

	sFiredText.setSize(20);
	sFiredText.setPosition(300, 450);

	sGotText.setSize(20);
	sGotText.setPosition(300, 510);
}

Highscore::~Highscore(){
}

void Highscore::HandleEvents(Game &game){
	sf::Event pEvent;
	
	while (game.window.pollEvent(pEvent)){
		//close
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);
		//menu
		if (pEvent.type == sf::Event::KeyPressed){
			if (pEvent.key.code == sf::Keyboard::Return)
				game.ChangeState(Game::gameStates::MAINMENU);
		}
	}
}
void Highscore::Update(Game &game){
	mng = game.highscore;

	if (!highscoreWritten)
	{
		ioHighscore.WriteHighscore(mng);
		highscoreWritten = true;
	}
	
	//Update stuff (there is the convertion from int to stringstream)
	pointText.Update(pointsStream, mng.getPoints());
	eMissedText.Update(eMissedStream, mng.getEnemyMissed());
	eKilledText.Update(eKilledStream, mng.getEnemyKilled());
	mKilledText.Update(mKilledStream, mng.getMonkeyKilled());
	sFiredText.Update(sFiredStream, mng.getShotsFired());
	sGotText.Update(sGotStream, mng.getShotsGot());
}
void Highscore::Render(Game &game){
	bg.Render(game.window);

	//Render stuff
	pointText.Render(game.window);
	eMissedText.Render(game.window);
	eKilledText.Render(game.window);
	mKilledText.Render(game.window);
	sFiredText.Render(game.window);
	sGotText.Render(game.window);
}