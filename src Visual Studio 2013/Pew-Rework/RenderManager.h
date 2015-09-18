//RenderManager.h

#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include <vector>

namespace Rm{


	template <class C>
	void StdDraw(std::vector<C> &vector, sf::RenderWindow &window){
		for (unsigned int i = 0; i < vector.size(); i++){
			if (vector[i].getActiveBool())
				vector[i].Render(window);
			else
				vector.erase(vector.begin() + i);
		}
	}
}
#endif