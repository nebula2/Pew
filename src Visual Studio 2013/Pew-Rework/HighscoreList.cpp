//HighscoreList.cpp

#include "HighscoreList.h"
#include <fstream>
#include <iostream>
#include <algorithm>


HighscoreList::HighscoreList(){

	//set the background
	m_bg.setFilePath("graphics/core/menu.png");

	//show something
	m_back.setStringAndSize("BACK", 50);
	m_back.setPosition(325, 500);

	m_highscore.setStringAndSize("HIGHSCORE", 50);
	m_highscore.setPosition(275, 10);

	//init highscorelist
	initHighscoreList();

	//init fadeOut
	initFading();
}

HighscoreList::~HighscoreList(){
	//Empty
}

void HighscoreList::HandleEvents(Game &game){
	sf::Event pEvent;

	while (game.window.pollEvent(pEvent)){
		//close
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);
		
		//Only accept Input when not fading out
		if (!m_startFading){
			//menu
			if (pEvent.type == sf::Event::KeyPressed){
				if (pEvent.key.code == sf::Keyboard::Return)
					m_startFading = true;
			}
		}
	}

	//Only accept Input when not fading out
	if (!m_startFading){
		//go to menu with mouse
		if (m_back.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(game.window).x, 
																(float)sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f))
			&& sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
			m_startFading = true;;
		}
	}
}
void HighscoreList::Update(Game &game){
	//update elapsedTime
	m_elapsedTime = (float)m_clock.restart().asMilliseconds();

	if (!m_startFading){
		//color the Back-Button
		if (m_back.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(game.window).x,
			(float)sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f))){
			m_back.setColor(sf::Color(255, 128, 0));
		}
		else{
			m_back.setColor(sf::Color(255, 255, 255));
		}
	}

	//See if we should change the ScreenState
	if (m_startFading){
		fadeOut();
		changeState(game);
	}
}
void HighscoreList::Render(Game &game){
	//Render Background
	m_bg.Render(game.window);

	//Render highscore attributes
	m_score.Render(game.window);
	m_accuracy.Render(game.window);
	m_points.Render(game.window);

	//Render button and highscore-text
	m_back.Render(game.window);
	m_highscore.Render(game.window);

	//draw fading sprite
	game.window.draw(m_fadingSprite);
}

//if the first integer is greater than the second, this returns true
bool HighscoreList::sortScoreDesc(const sf::Vector3<int>& a, const sf::Vector3<int>& b){
	return (a.z > b.z);
}

//initialize the highscore-list
void HighscoreList::initHighscoreList(){
	//first open the file
	std::fstream file;
	file.open("highscore.txt", std::ios::in);
	if (file.fail()){
		perror("could not load highscore.txt file\n");
	}

	//create some stuff for temp save
	std::string tmpPoints, tmpAccuracy, tmpScore; ///< to display in game later
	int tmpNumPoints, tmpNumFired, tmpNumGot, tmpint;

	//now extract the integer we need (points, shots fired, shots got, difficulty)
	while (file >> tmpNumPoints >> tmpint >> tmpint >> tmpint >> tmpNumFired >> tmpNumGot){

		//and store it into the integer
		//------------------------X--------------Y----------Z-------
		m_numInput.emplace_back(tmpNumPoints, tmpNumGot, tmpNumFired);
	}

	//won't need file anymore
	file.close();

	//convert the values of Vector3i to what we need (Points, Accuracy, Score)
	for (unsigned int i = 0; i < m_numInput.size(); i++){
		int tmpY, tmpZ;
		if (m_numInput[i].y != 0 && m_numInput[i].z != 0){
			tmpY = m_numInput[i].y * 100 / m_numInput[i].z; //get Accuracy
		}
		else{
			tmpY = 0;
		}
		if (m_numInput[i].x != 0 && tmpY != 0){
			tmpZ = m_numInput[i].x * tmpY / 100; //get Score (Points / Accuracy)
		}
		else{
			tmpZ = 0;
		}

		//set new values
		m_numInput[i].y = tmpY;
		m_numInput[i].z = tmpZ;
	}

	//sort the Vec for Score (Z) descending
	std::stable_sort(m_numInput.begin(), m_numInput.end(), sortScoreDesc);

	//erase all entries that are not in the top ten
	//but only if there are more than ten!
	if (m_numInput.size() > 10){
		m_numInput.resize(10);
	}

	//now we have a vector of integer, sorted by score which holds the TOP 10 plays
	//now put the data in a string

	for (unsigned int i = 0; i < m_numInput.size(); i++){

		//write Point-Data
		tmpPoints += "Points: ";
		std::ostringstream convert;
		convert << m_numInput[i].x;
		tmpPoints += convert.str();
		tmpPoints += "\n";

		//Write Accuracy-Data
		tmpAccuracy += " Accuracy: ";
		std::ostringstream convert2;
		convert2 << m_numInput[i].y;
		tmpAccuracy += convert2.str();
		tmpAccuracy += "\n";

		//Write Score-Data
		tmpScore += " Score: ";
		std::ostringstream convert3;
		convert3 << m_numInput[i].z;
		tmpScore += convert3.str();
		tmpScore += "\n";
	}

	//fill Highscore texts with data

	m_points.setStringAndSize(tmpPoints, 25);
	m_points.setPosition(50, 125);

	m_accuracy.setStringAndSize(tmpAccuracy, 25);
	m_accuracy.setPosition(275, 125);

	m_score.setStringAndSize(tmpScore, 25);
	m_score.setPosition(525, 125);
}

//Init fading
void HighscoreList::initFading(){

	if (!m_fadingTex.loadFromFile("graphics/core/settings.jpg")){
		perror("could not load fading graphic from \"graphics/core/settings.jpg\" \n");
	}
	m_fadingTex.setRepeated(true);

	m_fadingSprite.setTexture(m_fadingTex);
	m_fadingSprite.setPosition(0.0f, 0.0f);

	m_startFading = false;
	m_fadingAlpha = 0;
	m_fadingSprite.setColor(sf::Color(128, 128, 128, m_fadingAlpha));

}

//fade out by increasing the alpha-Value
void HighscoreList::fadeOut() {

	//increase as long as value is not 255
	if (m_fadingAlpha <= 255) {
		m_fadingAlpha += m_elapsedTime / 4;
		//set alpha
		m_fadingSprite.setColor(sf::Color(255, 255, 255, m_fadingAlpha));
	}
}

//change the state (after fadeOut is done)
void HighscoreList::changeState(Game& game){
	if (m_fadingAlpha >= 255){
		//Do Screen stuff
		game.ChangeState(Game::gameStates::MAINMENU);
	}
}