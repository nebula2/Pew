#include "Highscore.h"
void Highscore::setHighscoreManager(HighscoreManager pMng)
{
	mng = pMng;
}

int Highscore::Run(sf::RenderWindow &window)
{
	Backgrounds bg("graphics//lose.jpg");

	bool running = true;

	//make the highscore ready to be shown :D boojah
	GUItext			    pointText(20);
	pointText.setPosition  (300, 195);

	GUItext			  eMissedText(20);
	eMissedText.setPosition(300, 255);

	GUItext			  eKilledText(20);
	eKilledText.setPosition(300, 317);

	GUItext			  mKilledText(20);
	mKilledText.setPosition(300, 380);

	GUItext			   sFiredText(20);
	sFiredText.setPosition (300, 450);

	GUItext			     sGotText(20);
	sGotText.setPosition   (300, 510);
	

	while (running)
	 {
		 //handle events
		 while (window.pollEvent(event))
			{
             //close
			  if (event.type == sf::Event::Closed)
			    {
				    return (-1);
			    }
             //menu
		     if (event.type == sf::Event::KeyPressed)
			    {
					if (event.key.code == sf::Keyboard::Return)
				    {
                        return (0);
					}
				}
			}

		 //Update stuff (there is the convertion from int to stringstream)
		 pointText.Update(pointsStream, mng.getPoints());
		 eMissedText.Update(eMissedStream, mng.getEnemyMissed());
		 eKilledText.Update(eKilledStream, mng.getEnemyKilled());
		 mKilledText.Update(mKilledStream, mng.getMonkeyKilled());
		 sFiredText.Update(sFiredStream, mng.getShotsFired());
		 sGotText.Update(sGotStream, mng.getShotsGot());



		 window.clear();
		 bg.Render(window);

		 //Render stuff
		 pointText.Render(window);
		 eMissedText.Render(window);
		 eKilledText.Render(window);
		 mKilledText.Render(window);
		 sFiredText.Render(window);
		 sGotText.Render(window);

		 window.display();

	 }
	return -1;
}