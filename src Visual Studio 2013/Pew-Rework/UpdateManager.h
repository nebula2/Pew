//UpdateManager.h

#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

//SFML and windows header
#include <vector>

//own header
#include "EntityIncludes.h"
#include "IngameSfx.h"
#include "HighscoreManager.h"
#include "WeaponManager.h"


namespace UpdateManager{
	template <class C>
	void StdUpdate(std::vector<C> &vector, sf::RenderWindow &window, float &elapsedTime){
		for (unsigned int i = 0; i < vector.size(); i++)		{
			if (vector[i].active)
				vector[i].Update(window, elapsedTime);
		}
	}

	template <class C>
	void WeaponUpdate(std::vector<C> &vector, float &elapsedTime){
		for (unsigned int i = 0; i < vector.size(); i++)		{
			if (vector[i].active)
				vector[i].Update(elapsedTime);
		}
	}

	template <class C, class P1>
	void Boss2WeaponUpdate(std::vector<C> &vector,sf::RenderWindow &window, float &elapsedTime, P1 &player1){
		for (unsigned int i = 0; i < vector.size(); i++)		{
			if (vector[i].active)
				vector[i].Update(window, elapsedTime, player1);
		}
	}

	template <class C>
	void EnemyUpdate(std::vector<C> &vector, sf::RenderWindow &window, float &elapsedTime, HighscoreManager &highscore){
		for (unsigned int i = 0; i < vector.size(); i++){
			if (vector[i].active)
				vector[i].Update(window, elapsedTime, highscore);
		}
	}
}
#endif