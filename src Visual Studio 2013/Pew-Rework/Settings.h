//Settings.h

#ifndef SETTINGS_H
#define SETTINGS_H

#include "Game.h"
#include "MenuSfx.h"
#include "IOstuff.h"

class Settings : public GameState{
public:
	Settings();
	~Settings();

	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);
	
private:
	///PRIVATE MEMBER FUNCTIONS
	void initFading();
	void fadeOut();
	void changeState(Game& game);
	void updateMouseSelection();
	void updateButtonColor();
	bool mouseIsIntersecting();

	///PRIVATE MEMBER VARIABLES
	short int m_selection;		///< To see what has been selected
	int m_volume;				///< Volume for sound

	//myStuff
	IOsound m_iosound;			///< To read Volume-Setting
	MenuSound m_sound;			///< to handle the sound
	Background m_bg;			///< Background
	Text difficulty;			///< Buttons
	Text graphics;				///< Buttons
	Text sounds;				///< Buttons
	Text back;					///< Buttons
	sf::Rect<float> m_MouseRect;///< Rectangle for Mouse intersection

	//Statechange
	sf::Texture m_fadingTex;	///< Texture for fade IN/OUT
	sf::Sprite m_fadingSprite;	///< Sprite for fade IN/OUT
	float m_elapsedTime;		///< time elapsed in frame
	sf::Clock   m_clock;		///< Clock to measure elapsed Time
	bool m_startFading;			///< if this is true -> start increasing alpha
	int m_fadingAlpha;			///< Alpha-Value for fade IN/OUT
};

#endif