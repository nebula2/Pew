#ifndef __VECTOROPERATION_H__
#define __VECTOROPERATION_H__

#include <SFML\Graphics.hpp>

sf::Vector2f normalize(sf::Vector2f& source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0.0f){
		return sf::Vector2f(source.x / length, source.y / length);
	}
	else
		return source;
}

#endif