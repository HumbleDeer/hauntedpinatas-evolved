#ifndef SCREEN_2_HPP
#define SCREEN_2_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "cScreen.hpp"



class GameWindow : public cScreen
{
private:
    double PlayerSpeed;

    sf::Texture RoomTexture;
    sf::Texture PlayerStaticTexture[4];
    sf::Texture PlayerAnimateTexture[4];
    sf::Texture PinataTexture[4];

    sf::RectangleShape Player;
    sf::RectangleShape Pinata;

    sf::Sprite PlayerSprite;
    sf::Sprite PlayerAnimateSprite[4];

    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;

public:
    GameWindow(void);
    virtual int Run(sf::RenderWindow &App);
};

#endif // SCREEN_2_HPP
