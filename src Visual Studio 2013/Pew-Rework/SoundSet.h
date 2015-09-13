//SoundSet.h

#ifndef SOUNDSET_H
#define SOUNDSET_H

#include "Game.h"
#include "IOstuff.h"
#include <sstream>

class SoundSet : public GameState{
public:
	SoundSet();
	~SoundSet();

	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);

private:
	///PRIVATE MEMBER FUNCTIONS
	void initFading();
	void fadeOut();
	void changeState(Game& game);
	bool mouseIsIntersecting();

	///PRIVATE MEMBER VARIABLES
	int m_selection;					///< To see what has been selected
	int m_volume;						///< Volume for sound

	std::stringstream m_selectionStream;///< To display the volume

	//myStuff
	Background m_bg;					///< Background
	Text m_selectionString;				///< Text for volume
	IOsound m_iosound;					///< To read Volume-Setting	
	sf::Rect<float> m_MouseRect;		///< Rectangle for Mouse intersection

	//Statechange
	sf::Texture m_fadingTex;			///< Texture for fade IN/OUT
	sf::Sprite m_fadingSprite;			///< Sprite for fade IN/OUT
	float m_elapsedTime;				///< time elapsed in frame
	sf::Clock   m_clock;				///< Clock to measure elapsed Time
	bool m_startFading;					///< if this is true -> start increasing alpha
	int m_fadingAlpha;					///< Alpha-Value for fade IN/OUT
};

#endif