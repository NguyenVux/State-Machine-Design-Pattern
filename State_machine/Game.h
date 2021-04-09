#pragma once
#include "MenuState.h"
#include "MenuContext.h"
#include "MainMenu.h"
#include <algorithm>
#include <iostream>
#include <math.h>
#include "Util.h"

#define M_PI 3.14159265358979323846
class Player: public sf::CircleShape
{
private:
    sf::Vector2f direction;
    float velocity = 0.0f;
    const float drag;
    const float accel;
    const float maxV;
public:
    Player() : CircleShape(15.0f,3), drag(23.0f),accel(100.0f),maxV(250.0f)
    {
        setFillColor(sf::Color::Transparent);
        setOutlineColor(sf::Color::White);
        setOutlineThickness(3.0f);
        setOrigin(getRadius(), getRadius());
        setPosition(400, 300);
        direction = sf::Vector2f(0, 0);
    }
    void update(sf::RenderWindow& window,sf::Time dt);
};

class Bullet : public sf::RectangleShape
{
private:
    sf::Vector2f direction;
public:
    Bullet(sf::Vector2f dir) : RectangleShape(sf::Vector2f(30.0f, 30.0f))
    {
        direction.x = dir.x;
        direction.y = dir.y;
    }
    void update();
};





class Game :
    public MenuState
{
private:
    Player p;
    sf::Clock timer;
public:
    // Inherited via MenuState
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void update(sf::RenderWindow& window) override;
    ~Game()
    {
        std::cout << "Game deleted" << std::endl;
    }
};

