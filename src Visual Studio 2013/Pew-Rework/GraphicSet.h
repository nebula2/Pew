//GraphicSet.h

#ifndef GRAPHICSET_H
#define GRAPHICSET_H

#include "Game.h"
#include "IOstuff.h"
#include "MenuSfx.h"

class GraphicSet : public GameState{
public:
	GraphicSet();
	~GraphicSet();

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

	void initButtons();
	///PRIVATE MEMBER VARIABLES
	int m_volume;				///< Volume for sound

	bool m_selectionH;			///< Horizontal selected if true
	bool m_selectionV;			///< Vertical selected if true
	bool m_isSmooth;			///< Smooth setted if true
	bool m_isFull;				///< Fullscreen if true

	//myStuff
	Background m_bg;			///< Background
	IOscreen m_ioscreen;		///< Screensettings
	IOsmooth m_iosmooth;		///< Smoothsettings
	IOsound m_iosound;			///< Soundsettings
	MenuSound m_sound;			///< Soundplayer
	Text smooth;				///< Smooth Text
	Text fullscreen;			///< Fullscreen Text
	Text info;					///< Info-Text
	Text falseS;				///< Buttons | Smooth false
	Text falseF;				///< Buttons | Fullscreen false
	Text trueS;					///< Buttons | Smooth true
	Text trueF;					///< Buttons | Fullscreen true
	
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