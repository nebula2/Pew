//DiffSet.cpp

#include "DiffSet.h"

DiffSet::DiffSet(){
	//basic stuff
	m_selection = diff.ReadDiffSettings();
	bg.setFilePath("graphics/core/settings.jpg");

	//Sound
	m_iosound.ReadSoundSettings(m_volume);
	m_sound.LoadSoundBuffer();
	m_sound.setBuffer(m_volume);

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

	//init fadeOut
	initFading();
}
DiffSet::~DiffSet(){
	//Empty
}

void DiffSet::HandleEvents(Game &game){
	sf::Event pEvent;
	while (game.window.pollEvent(pEvent))	{
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		//Only accept Input when not fading out
		if (!m_startFading){
			//keyboard selection
			if (pEvent.type == sf::Event::KeyPressed){
				switch (pEvent.key.code){
				case sf::Keyboard::Up:
					if (m_selection > 1){
						m_selection -= 1;
						m_sound.PlaySound("select");
					}
					else
						m_selection = 1;
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
					diff.WriteDiffSettings(m_selection);
					m_startFading = true;
				case sf::Keyboard::Escape:
					m_startFading = true;
				default:
					break;
				}
			}
			//mouse selection
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mouseIsIntersecting()){
				diff.WriteDiffSettings(m_selection);
				m_startFading = true;
			}
		}//Endig !fadeOut
	}
}
void DiffSet::Update(Game &game){

	//update elapsedTime
	m_elapsedTime = (float)m_clock.restart().asMilliseconds();

	//Update Mouse Rectangle
	m_MouseRect = sf::Rect<float>((float)sf::Mouse::getPosition(game.window).x,
		(float)sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f);

	if (!m_startFading){
		//Update the mouse selection
		updateMouseSelection();

		//change the color depending on selection
		updateButtonColor();
	}

	//See if we should change the ScreenState
	if (m_startFading){
		fadeOut();
		changeState(game);
	}
}
void DiffSet::Render(Game &game){
	//Render Background
	bg.Render(game.window);
	
	//Render Buttons
	easy.Render(game.window);
	normal.Render(game.window);
	crazy.Render(game.window);
	info.Render(game.window);

	//draw fading sprite
	game.window.draw(m_fadingSprite);
}

//Init fading
void DiffSet::initFading(){

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
void DiffSet::fadeOut() {

	//increase as long as value is not 255
	if (m_fadingAlpha <= 255) {
		m_fadingAlpha += (int)m_elapsedTime / 4;
		//set alpha
		m_fadingSprite.setColor(sf::Color(255, 255, 255, m_fadingAlpha));
	}
}

//change the state (after fadeOut is done)
void DiffSet::changeState(Game& game){

	//Go back to Settings
	if (m_fadingAlpha >= 255){
		game.ChangeState(Game::gameStates::SETTINGS);			
	}
}

//Update the Selection done with the cursor
void DiffSet::updateMouseSelection(){
	//play
	if (easy.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 1){
			m_selection = 1;
			m_sound.PlaySound("select");
		}
	}

	//again
	if (normal.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 2){
			m_selection = 2;
			m_sound.PlaySound("select");
		}
	}
	//settings
	if (crazy.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 3){
			m_selection = 3;
			m_sound.PlaySound("select");
		}
	}
}

//Update the Color of the Buttons depending on their selection
void DiffSet::updateButtonColor(){
	if (m_selection == 1){//easy
		easy.setColor(sf::Color(255, 128, 0));
		normal.setColor(sf::Color(255, 255, 255));
		crazy.setColor(sf::Color(255, 255, 255));
	}
	else if (m_selection == 2){//normal
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

//returns true if mouse is intersecting with button
bool DiffSet::mouseIsIntersecting(){
	//play
	if (easy.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//again
	if (normal.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}
	//settings
	if (crazy.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//no intersection
	return false;
}