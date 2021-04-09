#pragma once
#include "SFML/Graphics.hpp"

template<class T>
sf::Vector2<T> normalize(sf::Vector2<T> a)
{

	float length = sqrt(a.x*a.x+a.y*a.y);
	if (length == 0.0f)
	{
		return a;
	}
	a /= length;
	return a;
}
