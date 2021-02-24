#include <SFML/Graphics.hpp>
#include "PauseMenu.hpp"

PauseMenu::PauseMenu(void)
{
    alpha_max = 3 * 255;
    alpha_div = 3;
    playing = false;
}

int PauseMenu::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;

    sf::Text Menu[5];
    sf::Color TextNormal = sf::Color(45,45,120);
    sf::Color TextActive = sf::Color(150,180,90);
    int menuIndex = 1;

    if (!Texture.loadFromFile("assets/menus/mainmenu.jpg"))
    {
        std::cerr << "Error loading mainmenu.jpg" << std::endl;
        return (-1);
    }
    Sprite.setTexture(Texture);

    if (!ButtonFont.loadFromFile("assets/ChillerStdRegular.otf"))
    {
        std::cerr << "Error loading ChillerStdRegular.otf" << std::endl;
        return (-1);
    }

    if (!TitleFont.loadFromFile("assets/InformalRoman.ttf"))
    {
        std::cerr << "Error loading nformalRoman.ttf" << std::endl;
        return (-1);
    }

    Menu[1].setFont(ButtonFont);
    Menu[1].setString("Play");
    Menu[1].setCharacterSize(52);
    Menu[1].setOutlineColor(TextNormal);
    Menu[1].setOutlineThickness(2);
    Menu[1].setPosition(sf::Vector2f((App.getSize().x / 2) - (Menu[1].getLocalBounds().width / 2),
                                     App.getSize().y / 1.5)
                       );


    Menu[2].setFont(ButtonFont);
    Menu[2].setString("Continue");
    Menu[2].setCharacterSize(52);
    Menu[2].setOutlineColor(TextNormal);
    Menu[2].setOutlineThickness(2);
    Menu[2].setPosition(sf::Vector2f((App.getSize().x / 2) - (Menu[2].getLocalBounds().width / 2),
                                     App.getSize().y / 1.5)
                       );

    Menu[3].setFont(ButtonFont);
    Menu[3].setCharacterSize(48);
    Menu[3].setString("Exit");
    Menu[3].setOutlineColor(TextNormal);
    Menu[3].setOutlineThickness(2);
    Menu[3].setPosition(sf::Vector2f(
                            ((App.getSize().x / (4)*3) + (App.getSize().x / (4 * 2)) *1) - (Menu[3].getLocalBounds().width / 2),
                            App.getSize().y / 1.325 )
                       );

    Menu[4].setFont(ButtonFont);
    Menu[4].setCharacterSize(48);
    Menu[4].setString("Help");
    Menu[4].setOutlineColor(TextNormal);
    Menu[4].setOutlineThickness(2);
    Menu[4].setPosition(sf::Vector2f(
                            ((App.getSize().x / (4)*0) + (App.getSize().x / (4 * 2)) *1) - (Menu[4].getLocalBounds().width / 2),
                            App.getSize().y / 1.325)
                       );

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
                case sf::Keyboard::Up:
                    Menu[1].setOutlineColor(TextActive);
                    Menu[2].setOutlineColor(TextActive);
                    Menu[4].setOutlineColor(TextNormal);
                    Menu[3].setOutlineColor(TextNormal);
                    if(!playing)menuIndex = 1;
                    else menuIndex = 2;
                    std::cout << menuIndex <<std::endl;
                    break;
                case sf::Keyboard::Left:
                    Menu[1].setOutlineColor(TextNormal);
                    Menu[2].setOutlineColor(TextNormal);
                    Menu[3].setOutlineColor(TextNormal);
                    Menu[4].setOutlineColor(TextActive);
                    menuIndex = 4;
                    std::cout << menuIndex <<std::endl;
                    break;
                case sf::Keyboard::Right:
                    Menu[1].setOutlineColor(TextNormal);
                    Menu[2].setOutlineColor(TextNormal);
                    Menu[3].setOutlineColor(TextActive);
                    Menu[4].setOutlineColor(TextNormal);
                    menuIndex = 3;
                    std::cout << menuIndex <<std::endl;
                    break;

                case sf::Keyboard::Return:
                    if (menuIndex == 1 || menuIndex == 2)
                    {
                        playing = true;
                        return (2); //--> Go to screen 1 (Game)

                    }else if (menuIndex == 4){
                        return (1); //--> Go to screen 2 (Help)
                    }
                    else if (menuIndex == 3)
                    {
                        App.close();
                        std::cout << "Goodbye!";
                    }
                    else{return (-1);}
                    break;
                default:
                    break;
                }
            }
        }
        Sprite.setColor(sf::Color(255, 255, 255, 255));
        /*
        if (menuIndex == 0) //if menu index is on play
        {
            Menu[1].setColor(sf::Color(255, 0, 0, 255)); //Play Red (if game closed)
            Menu[2].setColor(sf::Color(255, 255, 255, 255)); //Unselected, white, Exit
            Menu[3].setColor(sf::Color(255, 0, 0, 255)); //Continue Red (if game open)
            Menu[4].setColor(sf::Color(255, 255, 255, 255)); //Unselected, white, Help
        }
        else if (menu == 2) //Exit
        {
            Menu[1].setColor(sf::Color(255, 255, 255, 255)); //Unselected, Play Red (if game closed)
            Menu[2].setColor(sf::Color(255, 0, 0, 255)); //Exit, White
            Menu[3].setColor(sf::Color(255, 255, 255, 2555)); //Continue Red (if game open)
            Menu[4].setColor(sf::Color(255, 255, 255, 255)); //Unselected, white, Help
        }
        else if (menu == 4) //help
        {
            Menu[1].setColor(sf::Color(255, 255, 255, 255)); //Unselected, Play Red (if game closed)
            Menu[2].setColor(sf::Color(255, 255, 255, 255)); //Exit, White
            Menu[3].setColor(sf::Color(255, 255, 255, 2555)); //Continue Red (if game open)
            Menu[4].setColor(sf::Color(255, 0, 0, 255)); //Unselected, white, Help
        }*/

        //Clearing screen
        App.clear();
        //Drawing
        App.draw(Sprite);

        if (playing)
        {
            App.draw(Menu[2]);
        }
        else
        {
            App.draw(Menu[1]);
        }
        App.draw(Menu[3]);
        App.draw(Menu[4]);

        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
