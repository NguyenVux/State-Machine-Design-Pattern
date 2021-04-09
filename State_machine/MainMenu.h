#pragma once
#include "MenuState.h"
#include "MenuContext.h"
#include "Game.h"
class MainMenu : public MenuState
{
private:
	sf::Font font;
	sf::Text title;
	sf::Text menu[2];
	uint8_t choice = 0;
	sf::Clock delta_t;
public:
	MainMenu(int w, int h);
	void update(sf::RenderWindow& window) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~MainMenu();
};