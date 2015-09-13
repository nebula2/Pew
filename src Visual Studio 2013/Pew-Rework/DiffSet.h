//DiffSet.h

#ifndef DIFFSET_H
#define DIFFSET_H

#include "Game.h"
#include "IOstuff.h"
#include "MenuSfx.h"

class DiffSet : public GameState{
public:
	DiffSet();
	~DiffSet();

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
	int m_selection;			///< To see what has been selected
	int m_volume;				///< Volume for sound

	//MyStuff
	IOdiff diff;
	Background bg;
	IOsound m_iosound;			///< To read Volume-Setting
	MenuSound m_sound;			///< to handle the sound
	Text easy;					///< Buttons
	Text normal;				///< Buttons
	Text crazy;					///< Buttons
	Text info;					///< Buttons
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