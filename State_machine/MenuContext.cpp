
#include "MenuContext.h"

void MenuContext::changeState(MenuState* state)
{
	if (_state != nullptr)
	{
		delete _state;
		_state = state;
		_state->setContext(this);
	}
	else
	{
		_state = state;
		_state->setContext(this);
	}
}


void MenuContext::update(sf::RenderWindow& window)
{
	if (_state != nullptr)
	{
		_state->update(window);
	}
}

MenuContext::~MenuContext()
{
	if (_state != nullptr)
	{
		delete _state;
	}
}

void MenuContext::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (_state != nullptr)
	{
		target.draw(*_state, states);
	}
}
