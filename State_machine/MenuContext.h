#pragma once
#include "MenuState.h"
class MenuContext :
	public MenuState
{
private:
	MenuState* _state = nullptr;
public:
	void changeState(MenuState* state);
	void update(sf::RenderWindow& window) override;
	~MenuContext();

	// Inherited via MenuState
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;


};

