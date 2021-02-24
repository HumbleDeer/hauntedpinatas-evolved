#include "PauseMenu.hpp"

PauseMenu::PauseMenu(void)
{
    alpha_max = 3 * 255;
    alpha_div = 3;
    playing = false;
    pause_music.openFromFile("assets/sound/titlescreen-music.ogg");
    pause_music.setLoop(true);
}

int PauseMenu::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    if(pause_music.getStatus() == sf::Music::Status::Stopped)
        pause_music.play();

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
    Menu[2].setOutlineColor(TextActive);
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
                        pause_music.stop();
                        return (2); //--> Go to screen 1 (Game)

                    }else if (menuIndex == 4){

                        return (1); //--> Go to screen 2 (Help)
                    }
                    else if (menuIndex == 3)
                    {
                        App.close();
                        return (-1);
                    }
                    else{return (-1);}
                    break;
                case sf::Keyboard::Escape:
                    if(playing){ //If the game is already started, Escape will return you to the game immediately.
                        pause_music.stop();
                        return (2);
                    }else{
                    Menu[1].setOutlineColor(TextNormal);
                    Menu[2].setOutlineColor(TextNormal);
                    Menu[3].setOutlineColor(TextActive);
                    Menu[4].setOutlineColor(TextNormal);
                    menuIndex = 3;
                    }

                    std::cout << menuIndex <<std::endl;
                    break;
                default:
                    std::cout << "Unused key";
                    break;
                }
            }
        }
        Sprite.setColor(sf::Color(255, 255, 255, 255));

        App.clear();
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
