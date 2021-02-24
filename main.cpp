#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.hpp"

static const float VIEW_HEIGHT = 512.0f;
static const float VIEW_WIDTH = 512.0f;

int main(int argc, char** argv)
{
	//Applications variables
	std::vector<cScreen*> Screens;
	int screen = 0;
	// Create the main window
    sf::RenderWindow App(sf::VideoMode(700, 550, 32), "Haunted Piñatas Evolved", sf::Style::Titlebar | sf::Style::Close);
    sf::View AppView(sf::Vector2f(0.0f, 0.0f),sf::Vector2f())

	//Mouse cursor no more visible
	//App.setMouseCursorVisible(false);
	App.setKeyRepeatEnabled(false);

	//Screens preparations
	PauseMenu s0;
	Screens.push_back(&s0);
	HelpMenu s1;
	Screens.push_back(&s1);
	GameWindow s2;
	Screens.push_back(&s2);

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
}
