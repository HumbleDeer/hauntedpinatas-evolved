#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.hpp"

int main(int argc, char** argv)
{
	//Applications variables
	std::vector<cScreen*> Screens;
	int screen = 0;
	// Create the main window
    sf::RenderWindow App(sf::VideoMode(700, 550, 32), "Haunted Piñatas Evolved", sf::Style::Titlebar | sf::Style::Close);

	//Mouse cursor no more visible
	//App.setMouseCursorVisible(false);

	//Screens preparations
	PauseMenu s0;
	Screens.push_back(&s0);
	GameWindow s2;
	Screens.push_back(&s2);

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
}
