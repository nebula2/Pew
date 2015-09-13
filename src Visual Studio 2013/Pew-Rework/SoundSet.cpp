//SoundSet.cpp

#include "SoundSet.h"

SoundSet::SoundSet(){
	m_bg.setFilePath("graphics/core/soundset.jpg");

	m_selectionString.setSize(50);
	m_selectionString.setPosition(350, 250);
	m_selectionString.setColor(sf::Color::White);

	//read actual settings into volume
	m_iosound.ReadSoundSettings(m_volume);
	m_selection = m_volume;

	//init fading
	initFading();
}
SoundSet::~SoundSet(){
}

void SoundSet::HandleEvents(Game &game){
	sf::Event pEvent;
	while (game.window.pollEvent(pEvent)){
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		//Only accept Input when not fading out
		if (!m_startFading){
			//Keyboard selection
			if (pEvent.type == sf::Event::KeyPressed){
				switch (pEvent.key.code){
					//Increase Vol.
				case sf::Keyboard::Right:
				case sf::Keyboard::A:
					if (m_selection < 100)
						m_selection += 5;

					else
						m_selection = 100;
					break;
					//Decrease Vol.
				case sf::Keyboard::Left:
				case sf::Keyboard::D:
					if (m_selection > 0)
						m_selection -= 5;
					break;
					//Save or discard
				case sf::Keyboard::Escape:
					m_startFading = true;
					break;
				case sf::Keyboard::Return:
					m_iosound.WriteSoundSettings(m_selection);
					m_startFading = true;
					break;
				default:
					break;

				}
			}

			//mouse selection
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !mouseIsIntersecting()){
				m_iosound.WriteSoundSettings(m_selection);
				m_startFading = true;
			}

			//Increase Vol.
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mouseIsIntersecting()){
				if (m_selection < 100)
					m_selection += 5;
			}

			//Decrease Vol.
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && mouseIsIntersecting()){
				if (m_selection > 0)
					m_selection -= 5;
			}

		}//Endig !fadeOut
	}
}
void SoundSet::Update(Game &game){

	//update elapsedTime
	m_elapsedTime = (float)m_clock.restart().asMilliseconds();

	//Update Mouse Rectangle
	m_MouseRect = sf::Rect<float>((float)sf::Mouse::getPosition(game.window).x,
		(float)sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f);

	if (!m_startFading){
		m_selectionString.Update(m_selectionStream, m_selection);

		if (m_selection != game.getVolume())
			game.setVolume(m_selection);
	}

	//See if we should change the ScreenState
	if (m_startFading){
		fadeOut();
		changeState(game);
	}
}
void SoundSet::Render(Game &game){
	//Draw Background
	m_bg.Render(game.window);

	//Draw selection
	m_selectionString.Render(game.window);
	
	//draw fading sprite
	game.window.draw(m_fadingSprite);
}

//Init fading
void SoundSet::initFading(){

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
void SoundSet::fadeOut() {

	//increase as long as value is not 255
	if (m_fadingAlpha <= 255) {
		m_fadingAlpha += m_elapsedTime / 4;
		//set alpha
		m_fadingSprite.setColor(sf::Color(255, 255, 255, m_fadingAlpha));
	}
}

//change the state (after fadeOut is done)
void SoundSet::changeState(Game& game){

	//Go back to Settings
	if (m_fadingAlpha >= 255){
		game.ChangeState(Game::gameStates::SETTINGS);
	}
}

//returns true if mouse is intersecting with button
bool SoundSet::mouseIsIntersecting(){
	//play
	if (m_selectionString.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//no intersection
	return false;
}