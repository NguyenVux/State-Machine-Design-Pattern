#include <iostream>
#include "MenuState.h"
#include "MenuContext.h"
#include "MainMenu.h"





int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
	window.setKeyRepeatEnabled(false);
	MenuContext menu;
	menu.changeState(new MainMenu(800,600));
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		menu.update(window);
		window.draw(menu);
		window.display();
	}

	return 0;
}