#ifndef SCREEN_0_H
#define SCREEN_0_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "cScreen.hpp"

class PauseMenu : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;

	sf::Texture Texture;
    sf::Sprite Sprite;
    sf::Font ButtonFont;
    sf::Font TitleFont;
public:
	PauseMenu(void);
	sf::Music pause_music;
	virtual int Run(sf::RenderWindow &App);
};


#endif // SCREEN_0_H
