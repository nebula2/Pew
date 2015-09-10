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
	static bool sortScoreDesc(const sf::Vector3<int>& a, const sf::Vector3<int>& b); ///< Tells how to sort the Highscore


	Background m_bg; ///< the background to display

	Text m_score; ///< to display the score
	Text m_accuracy; ///< To display the accuracy
	Text m_points; ///< To display the points
	Text m_back; ///< For the User to get back to Main Menu
	Text m_highscore; ///< Just a text

	std::vector<sf::Vector3i> m_numInput; ///< holds the 3 important numbers
};

#endif //__HIGHSCORELIST_H__