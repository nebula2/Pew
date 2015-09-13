//HighscoreList.h

#ifndef __HIGHSCORELIST_H__
#define __HIGHSCORELIST_H__

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "IOstuff.h"

class HighscoreList : public GameState{
public:
	HighscoreList();
	~HighscoreList();

	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);

private:
	///PRIVATE MEMBER FUNCTIONS
	void initFading();
	void fadeOut();
	void changeState(Game& game);

	void initHighscoreList();

	///PRIVATE MEMBER VARIABLES
	static bool sortScoreDesc(const sf::Vector3<int>& a, const sf::Vector3<int>& b); ///< Tells how to sort the Highscore
	
	Background m_bg; ///< the background to display

	Text m_score; ///< to display the score
	Text m_accuracy; ///< To display the accuracy
	Text m_points; ///< To display the points
	Text m_back; ///< For the User to get back to Main Menu
	Text m_highscore; ///< Just a text

	std::vector<sf::Vector3i> m_numInput; ///< holds the 3 important numbers

	//Statechange
	sf::Texture m_fadingTex;	///< Texture for fade IN/OUT
	sf::Sprite m_fadingSprite;	///< Sprite for fade IN/OUT
	float m_elapsedTime;		///< time elapsed in frame
	sf::Clock   m_clock;		///< Clock to measure elapsed Time
	bool m_startFading;			///< if this is true -> start increasing alpha
	int m_fadingAlpha;			///< Alpha-Value for fade IN/OUT
};

#endif //__HIGHSCORELIST_H__