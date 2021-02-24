#ifndef SCREEN_1_HPP
#define SCREEN_1_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "cScreen.hpp"



class HelpMenu : public cScreen
{
private:
    sf::Texture bgTexture;

    sf::Sprite Background;
    sf::Text Title;
    sf::Text Text;
    sf::Font ButtonFont;
    sf::Font TitleFont;

    sf::Event Event;

    bool Running;
public:
    HelpMenu(void);
    virtual int Run(sf::RenderWindow &App);
};

#endif // SCREEN_1_HPP

