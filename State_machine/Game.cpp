#include "Game.h"

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(p);
}

void Game::update(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		context->changeState(new MainMenu(window.getSize().x, window.getSize().y));
	}
	p.update(window,timer.restart());
}



void Player::update(sf::RenderWindow& window,sf::Time dt)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotate(-70 * dt.asSeconds());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotate(70 * dt.asSeconds());
	}
	sf::Vector2f thrust(sinf(-getRotation() * M_PI / 180.0), cosf(-getRotation() * M_PI / 180.0));
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		velocity -= accel * dt.asSeconds();
		//direction *= -1.0f;
		direction += thrust;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		velocity += accel*dt.asSeconds();
		direction += thrust;
	}
	velocity = std::min(maxV, velocity);
	direction = normalize(direction);
	
	if (velocity > 0.000f)
	{
		velocity -= drag * dt.asSeconds();
	}
	else if(velocity<0.0f)
	{
		velocity += drag * dt.asSeconds();
	}
	//velocity = std::max(velocity, 0.0f);
	move(direction * (velocity * dt.asSeconds()));
	if (getPosition().x > window.getSize().x || getPosition().y > window.getSize().y)
	{
		setPosition((int(getPosition().x) % window.getSize().x), (int(getPosition().y) % window.getSize().y));
	}
	else 
	{
		if (getPosition().x < 0)
		{
			setPosition(window.getSize().x, getPosition().y);
		}
		if (getPosition().y < 0)
		{
			setPosition(getPosition().x, window.getSize().y);
		}
	}
}

void Bullet::update()
{
	move(direction);
}
