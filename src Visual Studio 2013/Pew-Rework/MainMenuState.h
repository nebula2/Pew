//MainMenuState.h

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "Game.h"
#include "MenuSfx.h"
#include "IOstuff.h"

class MainMenuState : public GameState{
public:
	MainMenuState();
	~MainMenuState();
	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);

private:
	///PRIVATE MEMBER FUNCTIONS
	void initFading();
	void fadeOut();
	void changeState(Game& game);
	bool mouseIsIntersecting();

	void initEnemy();
	void initButtons();
	void updateButtonColor();
	void updateEnemy();
	void updateMouseSelection();

	///PRIVATE MEMBER VARIABLES

	//Menu related
	IOsound m_iosound;			///< To read Volume-Setting
	MenuSound m_sound;			///< to handle the sound
	Background m_bg;			///< Background
	Text play;					///< Buttons
	Text again;					///< Buttons
	Text highscore;				///< Buttons
	Text settings;				///< Buttons
	Text close;					///< Buttons

	short int m_selection;		///< To see what has been selected
	int m_volume;				///< Volume for sound

	sf::Rect<float> m_MouseRect;///< Rectangle for Mouse intersection

	//Enemy related
	float m_elapsedTime;		///< time elapsed in frame
	float m_x_movement;			///< X-Movement (circle calc)
	float m_y_movement;			///< Y-Movement (circle calc)
	float m_xPos;				///< X-Position
	float m_yPos;				///< Y-Position

	short int m_debauch;		///< Debauch (circle calc)
	
	sf::Clock   m_clock;		///< Clock to measure elapsed Time
	sf::Texture m_texture;		///< Texture of the Enemy
	sf::Sprite  m_sprite;		///< Sprite for the Texture

	//Statechange
	sf::Texture m_fadingTex;	///< Texture for fade IN/OUT
	sf::Sprite m_fadingSprite;	///< Sprite for fade IN/OUT
	bool m_startFading;			///< if this is true -> start increasing alpha
	int m_fadingAlpha;			///< Alpha-Value for fade IN/OUT
};
#endif