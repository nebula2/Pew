//Settings.cpp

#include "Settings.h"


Settings::Settings(){
	//sound
	m_iosound.ReadSoundSettings(m_volume);
	m_sound.LoadSoundBuffer();
	m_sound.setBuffer(m_volume);

	m_selection = 0;

	//background
	m_bg.setFilePath("graphics/core/settings.png");

	//buttons
	difficulty.setStringAndSize("Difficulty", 70);
	graphics.setStringAndSize("Graphics", 70);
	sounds.setStringAndSize("Sound", 70);
	back.setStringAndSize("Back", 70);


	difficulty.setPosition(270, 100);
	sounds.setPosition(270, 200);
	graphics.setPosition(270, 300);
	back.setPosition(270, 400);

	//init fadeOut
	initFading();
}
Settings::~Settings(){
	//Empty
}

void Settings::HandleEvents(Game &game){
	sf::Event pEvent;

	while (game.window.pollEvent(pEvent))	{
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		//Only accept Input when not fading out
		if (!m_startFading){
			//keyboard
			if (pEvent.type == sf::Event::KeyPressed){
				switch (pEvent.key.code){
				case sf::Keyboard::Up:
					if (m_selection > 0){
						m_selection -= 1;
						m_sound.PlaySound("select");
					}
					else
						m_selection = 0;
					break;
				case sf::Keyboard::Down:
					if (m_selection < 3){
						m_selection += 1;
						m_sound.PlaySound("select");
					}
					else
						m_selection = 3;
					break;
				case sf::Keyboard::Return:
					m_startFading = true;
					break;
				default:
					break;
				}
			}
			//mouse selection
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mouseIsIntersecting()){
				m_startFading = true;
			}
		}//End if !fadeOut
	}
}

void Settings::Update(Game &game){

	//update elapsedTime
	m_elapsedTime = (float)m_clock.restart().asMilliseconds();

	//Update Mouse Rectangle
	m_MouseRect = sf::Rect<float>((float)sf::Mouse::getPosition(game.window).x,
		(float)sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f);

	if (!m_startFading){
		//Update Mouse selection
		updateMouseSelection();

		//Color the buttons
		updateButtonColor();
	}

	//See if we should change the ScreenState
	if (m_startFading){
		fadeOut();
		changeState(game);
	}
}
void Settings::Render(Game &game){
	//Render background
	m_bg.Render(game.window);

	//Render Buttons
	graphics.Render(game.window);
	difficulty.Render(game.window);
	sounds.Render(game.window);
	back.Render(game.window);

	//draw fading sprite
	game.window.draw(m_fadingSprite);
}

//Init fading
void Settings::initFading(){

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
void Settings::fadeOut() {

	//increase as long as value is not 255
	if (m_fadingAlpha <= 255) {
		m_fadingAlpha += (int)m_elapsedTime / 4;
		//set alpha
		m_fadingSprite.setColor(sf::Color(255, 255, 255, m_fadingAlpha));
	}
}

//change the state (after fadeOut is done)
void Settings::changeState(Game& game){
	if (m_fadingAlpha >= 255){

		if (m_selection == 0)//diff
			game.ChangeState(Game::gameStates::DIFFSET);

		else if (m_selection == 1)//sound
			game.ChangeState(Game::gameStates::SOUNDSET);

		else if (m_selection == 2)//graphics
			game.ChangeState(Game::gameStates::GRAPHICSET);

		else//back
			game.ChangeState(Game::gameStates::MAINMENU);
	}
}

//Update the Selection done with the cursor
void Settings::updateMouseSelection(){
	//Difficulty
	if (difficulty.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 0){
			m_selection = 0;
			m_sound.PlaySound("select");
		}
	}

	//sounds
	if (sounds.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 1){
			m_selection = 1;
			m_sound.PlaySound("select");
		}
	}
	//graphics
	if (graphics.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 2){
			m_selection = 2;
			m_sound.PlaySound("select");
		}
	}
	//back
	if (back.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 3){
			m_selection = 3;
			m_sound.PlaySound("select");
		}
	}
}

//Update the Color of the Buttons depending on their selection
void Settings::updateButtonColor(){

	if (m_selection == 0){//diff
		difficulty.setColor(sf::Color(255, 128, 0));
		graphics.setColor(sf::Color(255, 255, 255));
		sounds.setColor(sf::Color(255, 255, 255));
		back.setColor(sf::Color(255, 255, 255));
	}
	else if (m_selection == 1){//sound
		difficulty.setColor(sf::Color(255, 255, 255));
		graphics.setColor(sf::Color(255, 255, 255));
		sounds.setColor(sf::Color(255, 128, 0));
		back.setColor(sf::Color(255, 255, 255));
	}
	else if (m_selection == 2){//Graphics
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

//returns true if mouse is intersecting with button
bool Settings::mouseIsIntersecting(){
	//Difficulty
	if (difficulty.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//sounds
	if (sounds.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}
	//graphics
	if (graphics.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}
	//back
	if (back.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//no intersection
	return false;
}