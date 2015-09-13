//MainMenuState.cpp

#define PI 3.14159
#include "MainMenuState.h"
#include <cmath>

MainMenuState::MainMenuState(){
	m_bg.setFilePath("graphics/core/menu.png");
	
	//sound & music
	m_iosound.ReadSoundSettings(m_volume);
	m_sound.LoadSoundBuffer();
	m_sound.setBuffer(m_volume);

	m_selection = 0;

	//initialize enemy
	initEnemy();

	//initialize buttons
	initButtons();

	//initialize Fading
	initFading();
}

MainMenuState::~MainMenuState(){
}

void MainMenuState::HandleEvents(Game &game){
	sf::Event pEvent;

	while (game.window.pollEvent(pEvent)){
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		//Only accept Input when not fading out
		if (!m_startFading){
			//Keyboard selection
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
		}
		//mouse selection
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mouseIsIntersecting()){
			m_startFading = true;
		}
	}//End if !fadeOut
}

void MainMenuState::Update(Game &game){

	//Update Mouse Rectangle
	m_MouseRect = sf::Rect<float>((float)sf::Mouse::getPosition(game.window).x,
								  (float)sf::Mouse::getPosition(game.window).y + 1.0f, 1.0f, 1.0f);

	//check for Mouse selection if not fading out
	if (!m_startFading){
		updateMouseSelection();
	}

	//Do color shit
	updateButtonColor();


	//moving enemy
	updateEnemy();

	//See if we should change the ScreenState
	if (m_startFading){
		fadeOut();
		changeState(game);
	}
}

void MainMenuState::Render(Game &game){
	//draw Background
	m_bg.Render(game.window);

	//draw enemy Sprite
	game.window.draw(m_sprite);

	//draw Buttons
	settings.Render(game.window);
	close.Render(game.window);
	highscore.Render(game.window);

	if (game.getIntroPlayed())
		again.Render(game.window);
	else
		play.Render(game.window);

	//draw fading sprite
	game.window.draw(m_fadingSprite);
}

//Init fading
void MainMenuState::initFading(){

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
void MainMenuState::fadeOut() {

	//increase as long as value is not 255
	if (m_fadingAlpha <= 255) {
		m_fadingAlpha += m_elapsedTime / 4;
		//set alpha
		m_fadingSprite.setColor(sf::Color(255, 255, 255, m_fadingAlpha));
	}
}

//change the state (after fadeOut is done)
void MainMenuState::changeState(Game& game){
	//if the fadeOut is done we are ready to change the screen
	if (m_fadingAlpha >= 255){

		//Go to the game
		if (m_selection == 0){
			if (!game.getIntroPlayed())
				game.ChangeState(Game::gameStates::INTRO);

			else{
				game.setIntroPlayed(true);
				game.ChangeState(Game::gameStates::PLAY);
			}
		}

		//Go to the HighscoreList
		else if (m_selection == 1){
			game.ChangeState(Game::gameStates::HIGHSCORELIST);
		}

		//Go to the Settings
		else if (m_selection == 2){
			game.ChangeState(Game::gameStates::SETTINGS);
		}

		//Close the Game
		else if (m_selection == 3){
			game.setRunning(false);
		}
	}
}

//set Up Variables and Stuff for the Enemy
void MainMenuState::initEnemy(){

	m_elapsedTime = 0.0f;
	m_x_movement = 0.0f;
	m_y_movement = 0.0f;
	m_debauch = 200;

	m_texture.loadFromFile("graphics/enemies/enemy.png");
	m_texture.setSmooth(false);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin((float)m_texture.getSize().x / 2.0f, (float)m_texture.getSize().y / 2.0f);
}

//set up the Buttons
void MainMenuState::initButtons(){

	play.setStringAndSize("play", 70);
	play.setPosition(270, 150);

	again.setStringAndSize("again", 70);
	again.setPosition(270, 150);

	highscore.setStringAndSize("highscore", 70);
	highscore.setPosition(270, 250);

	settings.setStringAndSize("settings", 70);
	settings.setPosition(270, 350);

	close.setStringAndSize("close", 70);
	close.setPosition(270, 450);
}

//Update the Color of the Buttons depending on their selection
void MainMenuState::updateButtonColor(){

	//Play
	if (m_selection == 0){
		play.setColor(sf::Color(255, 128, 0));
		again.setColor(sf::Color(255, 128, 0));
		highscore.setColor(sf::Color(255, 255, 255));
		settings.setColor(sf::Color(255, 255, 255));
		close.setColor(sf::Color(255, 255, 255));
	}

	//Highscore
	else if (m_selection == 1){
		play.setColor(sf::Color(255, 255, 255));
		again.setColor(sf::Color(255, 255, 255));
		highscore.setColor(sf::Color(255, 128, 0));
		settings.setColor(sf::Color(255, 255, 255));
		close.setColor(sf::Color(255, 255, 255));
	}

	//Settings
	else if (m_selection == 2){
		play.setColor(sf::Color(255, 255, 255));
		again.setColor(sf::Color(255, 255, 255));
		highscore.setColor(sf::Color(255, 255, 255));
		settings.setColor(sf::Color(255, 128, 0));
		close.setColor(sf::Color(255, 255, 255));
	}

	//Close
	else{
		play.setColor(sf::Color(255, 255, 255));
		again.setColor(sf::Color(255, 255, 255));
		highscore.setColor(sf::Color(255, 255, 255));
		settings.setColor(sf::Color(255, 255, 255));
		close.setColor(sf::Color(255, 128, 0));
	}
}

//Update the Enemy
void MainMenuState::updateEnemy(){

	//get the elapsed time
	m_elapsedTime = (float)m_clock.restart().asMilliseconds();
	m_x_movement += m_elapsedTime / 4;
	m_y_movement += m_elapsedTime / 4;

	//set the Position
	m_yPos = 300 + (float)std::sin((m_y_movement * PI) / 180) * m_debauch;
	m_xPos = 400 + (float)std::cos((m_x_movement * PI) / 180) * m_debauch;

	if (m_x_movement > 360)
		m_x_movement = 0;

	if (m_y_movement > 360)
		m_y_movement = 0;

	m_sprite.setPosition(m_xPos, m_yPos);
}

//Update the Selection done with the cursor
void MainMenuState::updateMouseSelection(){
	//play
	if (play.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 0){
			m_selection = 0;
			m_sound.PlaySound("select");
		}
	}

	//again
	if (again.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 0){
			m_selection = 0;
			m_sound.PlaySound("select");
		}
	}

	//highscorelist
	if (highscore.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 1){
			m_selection = 1;
			m_sound.PlaySound("select");
		}
	}
	//settings
	if (settings.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 2){
			m_selection = 2;
			m_sound.PlaySound("select");
		}
	}
	//close
	if (close.getGlobalBounds().intersects(m_MouseRect)){
		if (m_selection != 3){
			m_selection = 3;
			m_sound.PlaySound("select");
		}
	}
}

//returns true if mouse is intersecting with button
bool MainMenuState::mouseIsIntersecting(){
	//play
	if (play.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//again
	if (again.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//highscorelist
	if (highscore.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}
	//settings
	if (settings.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}
	//close
	if (close.getGlobalBounds().intersects(m_MouseRect)){
		return true;
	}

	//no intersection
	return false;
}