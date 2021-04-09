#pragma once
#include "SFML/Graphics.hpp"
class MenuContext;
class MenuState : public sf::Drawable
{
protected:
	MenuContext* context;
public:
	void setContext(MenuContext* context);
	virtual void update(sf::RenderWindow& window) = 0;
};