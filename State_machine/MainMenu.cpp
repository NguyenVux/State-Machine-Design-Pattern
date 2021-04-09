#include "MainMenu.h"


MainMenu::MainMenu(int w, int h)
{
	if (!font.loadFromFile("default.ttf"))
	{
		throw "Unable to load font";
	}
	title.setFont(font);
	title.setString("ASTEROID");
	title.setCharacterSize(100);
	sf::FloatRect rect = title.getLocalBounds();
	title.setOrigin(rect.width/2.0,rect.height);
	title.setPosition(w / 2.0, 150);

	menu[0].setString("Start Game");
	menu[1].setString("Exit");

	menu[0].setFont(font);
	menu[1].setFont(font);
	rect = menu[0].getLocalBounds();
	menu[0].setOrigin(rect.width / 2.0, rect.height);
	menu[0].setPosition(w / 2.0, 250);

	rect = menu[1].getLocalBounds();
	menu[1].setOrigin(rect.width / 2.0, rect.height);
	menu[1].setPosition(w / 2.0, menu[0].getPosition().y+rect.height+50);
	menu[choice].setFillColor(sf::Color::Red);
}

void MainMenu::update(sf::RenderWindow &window)
{
	bool is_press = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && delta_t.restart().asMilliseconds() > 50)
	{
		is_press = true;
		choice =(choice-1)%2+((choice-1)%2<0)*2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && delta_t.restart().asMilliseconds() > 50)
	{
		is_press = true;
		choice = (choice + 1) % 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (choice == 1)
		{
			window.close();
		}
		else if(choice == 0)
		{
			context->changeState(new Game());
		}
	}
	for (uint8_t i = 0; is_press && i < 2; i++)
	{
		if (i == choice)
		{
			menu[i].setFillColor(sf::Color::Red);
		}
		else
		{
			menu[i].setFillColor(sf::Color::White);
		}
	}
}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(title);
	for (uint8_t i = 0; i < 2; i++)
	{
		target.draw(menu[i]);
	}
}

MainMenu::~MainMenu()
{
	std::cout << "Main menu deleted" << std::endl;
}
