#include "HelpMenu.hpp"
#include <SFML/Graphics.hpp>

HelpMenu::HelpMenu(void)
{
    bgTexture.loadFromFile("assets/menus/mainmenu.jpg");
    Background.setTexture(bgTexture);
    Background.setColor(sf::Color(128, 128, 128, 250));

    ButtonFont.loadFromFile("assets/ChillerStdRegular.otf");
    TitleFont.loadFromFile("assets/InformalRoman.ttf");
    Running = true;
}

int HelpMenu::Run(sf::RenderWindow &App)
{
    while (Running)
    {
        //Verifying events
        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Escape:
                    return (0);
                    break;
                }
            }
        }

        Title.setCharacterSize(58);
        Title.setString("Haunted Piñatas");
        Title.setFillColor(sf::Color::White);
        Title.setFont(TitleFont);
        Title.setPosition(sf::Vector2f((App.getSize().x / 2) - (Title.getLocalBounds().width / 2),
                                     80
                       ));

        //Clearing screen
        App.clear(sf::Color(0, 0, 0, 0));
        //Drawing
        App.draw(Background);
        App.draw(Title);
        App.draw(Text);
        App.display();
    }

//Never reaching this point normally, but just in case, exit the application
    return -1;
}
