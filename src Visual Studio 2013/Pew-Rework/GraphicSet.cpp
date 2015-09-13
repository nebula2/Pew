//GraphicSet.cpp

#include "GraphicSet.h"

GraphicSet::GraphicSet(){
	//basic stuff
	m_bg.setFilePath("graphics/core/settings.jpg");

	m_isFull = m_ioscreen.getScreenSettings();

	if (m_iosmooth.ReadSmoothSettings())
		m_isSmooth = false;
	else
		m_isSmooth = true;

	m_selectionH = false;
	m_selectionV = false;

	//Sound
	m_iosound.ReadSoundSettings(m_volume);
	m_sound.LoadSoundBuffer();
	m_sound.setBuffer(m_volume);

	//buttons
	initButtons();

	//init fadeOut
	initFading();
}

GraphicSet::~GraphicSet(){
	//Empty
}

void GraphicSet::HandleEvents(Game &game){
	sf::Event pEvent;
	while (game.window.pollEvent(pEvent)){
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		//Only accept Input when not fading out
		if (!m_startFading){
			//keyboard selection
			if (pEvent.type == sf::Event::KeyPressed){
				switch (pEvent.key.code){
					//horizontal
				case sf::Keyboard::Up:
					if (m_selectionV){
						m_selectionV = false;
						m_sound.PlaySound("select");
					}
					else
						m_selectionV = false;
					break;
				case sf::Keyboard::Down:
					if (!m_selectionV){
						m_selectionV = true;
						m_sound.PlaySound("select");
					}
					else
						m_selectionV = true;
					break;
					//vertical
				case sf::Keyboard::Right:
					if (!m_selectionH){
						m_selectionH = true;
						m_sound.PlaySound("select");
					}
					else
						m_selectionH = true;
					break;
				case sf::Keyboard::Left:
					if (m_selectionH){
						m_selectionH = false;
						m_sound.PlaySound("select");
					}
					else
						m_selectionH = false;
					break;
					//confirm or discard
				case sf::Keyboard::Return:
					m_ioscreen.setScreenSettings(m_isFull);
					m_iosmooth.WriteSmoothSettings(m_isSmooth);
					m_startFading = true;
					break;
				case sf::Keyboard::Escape:
					m_startFading = true;
					break;
				default:
					break;
				}
			}
			//mouse selection
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mouseIsIntersecting()){
				m_ioscreen.setScreenSettings(m_isFull);
				m_iosmooth.WriteSmoothSettings(m_isSmooth);
				m_startFading = true;
			}

		}//Endig !fadeOut
	}
}
void GraphicSet::Update(Game &game)
{
	//update elapsedTime
	m_elapsedTime = (float)m_clock.restart().asMilliseconds();

	//Update Mouse Rectangle
	m_MouseRect = sf::Rect<float>((float)sf::Mouse::getPosition(game.window).x,
		(float)sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f);


	if (!m_startFading){

		//set bools depending on selection
		if (m_selectionH && m_selectionV)
			m_isFull = true;

		else if (!m_selectionH && !m_selectionV)
			m_isSmooth = false;

		else if (m_selectionH && !m_selectionV)
			m_isSmooth = true;

		else if (!m_selectionH && m_selectionV)
			m_isFull = false;

		//Update the mouse selection
		updateMouseSelection();

		//change color depending on selection
		updateButtonColor();
	}

	//See if we should change the ScreenState
	if (m_startFading){
		fadeOut();
		changeState(game);
	}
}
void GraphicSet::Render(Game &game){
	//Render Background
	m_bg.Render(game.window);

	//Render Texts
	smooth.Render(game.window);
	fullscreen.Render(game.window);
	info.Render(game.window);

	//Render buttons
	trueS.Render(game.window);
	falseS.Render(game.window);
	trueF.Render(game.window);
	falseF.Render(game.window);

	//draw fading sprite
	game.window.draw(m_fadingSprite);
}

//Initialize Buttons
void GraphicSet::initButtons(){
	smooth.setStringAndSize("Smooth", 70);
	fullscreen.setStringAndSize("Fullscreen", 70);
	falseS.setStringAndSize("false", 50);
	falseF.setStringAndSize("false", 50);
	trueS.setStringAndSize("true", 50);
	trueF.setStringAndSize("true", 50);
	info.setStringAndSize("enter = save, esc = back", 40);

	smooth.setPosition(50, 75);
	smooth.setColor(sf::Color(255, 128, 0));
	falseS.setPosition(480, 95);
	trueS.setPosition(630, 95);

	fullscreen.setPosition(50, 300);
	fullscreen.setColor(sf::Color(255, 128, 0));
	falseF.setPosition(480, 320);
	trueF.setPosition(630, 320);

	info.setPosition(50, 500);
	info.setColor(sf::Color(255, 128, 0));
}

//Init fading
void GraphicSet::initFading(){

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
void GraphicSet::fadeOut() {

	//increase as long as value is not 255
	if (m_fadingAlpha <= 255) {
		m_fadingAlpha += m_elapsedTime / 4;
		//set alpha
		m_fadingSprite.setColor(sf::Color(255, 255, 255, m_fadingAlpha));
	}
}

//change the state (after fadeOut is done)
void GraphicSet::changeState(Game& game){

	//Go back to Settings
	if (m_fadingAlpha >= 255){
		game.ChangeState(Game::gameStates::SETTINGS);
	}
}

//Update the Selection done with the cursor
void GraphicSet::updateMouseSelection(){

	//Smooth false
	if (falseS.getGlobalBounds().intersects(m_MouseRect)){
		if (m_isSmooth){
			m_selectionH = false;
			m_selectionV = false;
			m_isSmooth = false;
			m_sound.PlaySound("select");
		}
	}

	//Smooth true
	if (trueS.getGlobalBounds().intersects(m_MouseRect)){
		if (!m_isSmooth){
			m_selectionH = true;
			m_selectionV = false;
			m_isSmooth = true;
			m_sound.PlaySound("select");
		}
	}

	//Fullscreen false
	if (falseF.getGlobalBounds().intersects(m_MouseRect)){
		if (m_isFull){
			m_selectionH = false;
			m_selectionV = true;
			m_isFull = false;
			m_sound.PlaySound("select");
		}
	}

	//Fullscreen true
	if (trueF.getGlobalBounds().intersects(m_MouseRect)){
		if (!m_isFull){
			m_selectionH = true;
			m_selectionV = true;
			m_isFull = true;
			m_sound.PlaySound("select");
		}
	}
}

//Update the Color of the Buttons depending on their selection
void GraphicSet::updateButtonColor(){
	if (!m_selectionV){
		if (m_isFull){
			falseF.setColor(sf::Color(255, 255, 255));
			trueF.setColor(sf::Color(255, 128, 0));
		}
		if (!m_isFull){
			falseF.setColor(sf::Color(255, 128, 0));
			trueF.setColor(sf::Color(255, 255, 255));
		}
		if (!m_selectionH){
			falseS.setColor(sf::Color(255, 128, 0));
			trueS.setColor(sf::Color(255, 255, 255));
		}
		if (m_selectionH){
			falseS.setColor(sf::Color(255, 255, 255));
			trueS.setColor(sf::Color(255, 128, 0));
		}
	}

	if (m_selectionV){
		if (m_isSmooth){
			falseS.setColor(sf::Color(255, 255, 255));
			trueS.setColor(sf::Color(255, 128, 0));
		}
		if (!m_isSmooth){
			falseS.setColor(sf::Color(255, 128, 0));
			trueS.setColor(sf::Color(255, 255, 255));
		}
		if (!m_selectionH){
			falseF.setColor(sf::Color(255, 128, 0));
			trueF.setColor(sf::Color(255, 255, 255));
		}
		if (m_selectionH){
			falseF.setColor(sf::Color(255, 255, 255));
			trueF.setColor(sf::Color(255, 128, 0));
		}
	}
}

//returns true if mouse is intersecting with button
bool GraphicSet::mouseIsIntersecting(){
	//Smooth false
	if (falseS.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//Smooth true
	if (trueS.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//Fullscreen false
	if (falseF.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//Fullscreen true
	if (trueF.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//no intersection
	return false;
}