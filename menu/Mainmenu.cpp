#include "Mainmenu.h"

MainMenu::MainMenu(float width, float height)
{
    menuFont_Button.loadFromFile("assets/InformalRoman.ttf");
    menuFont_Title.loadFromFile("assets/ChillerStdRegular.ttf");
    menuFont_Text.loadFromFile("");

    menuTexture_Start.loadFromFile("assets/menus/mainmenu.jpg");

    menuText_Static = sf::Color(45,45,120);
    menuText_Active = sf::Color(150,180,90);

    //Play button
    menuText[0].setFont(menuFont_Button);
    menuText[0].setFillColor(menuText_Static);
    menuText[0].setString("Play");
    menuText[0].setCharacterSize(48);
    menuText[0].setPosition(sf::Vector2f(
                                ((width / (MAX_NUMBER_OF_ITEMS)*0) + (width / (MAX_NUMBER_OF_ITEMS * 2)) *1) - (menuText[0].getLocalBounds().width / 2),
                                height / 1.325)
                           );

    //Instructions button
    menuText[1].setFont(menuFont_Button);
    menuText[1].setFillColor(menuText_Static);
    menuText[1].setString("Instructions");
    menuText[1].setPosition(sf::Vector2f(
                                ((width / (MAX_NUMBER_OF_ITEMS)*1) + (width / (MAX_NUMBER_OF_ITEMS * 2)) *1) - (menuText[1].getLocalBounds().width / 2),
                                height / 1.325)
                           );

    menuText[2].setFont(menuFont_Button);
    menuText[2].setFillColor(menuText_Static);
    menuText[2].setString("Quit");
    menuText[2].setCharacterSize(48);
    menuText[2].setPosition(sf::Vector2f(
                                ((width / (MAX_NUMBER_OF_ITEMS)*2) + (width / (MAX_NUMBER_OF_ITEMS * 2)) *1) - (menuText[2].getLocalBounds().width / 2),
                                height / 1.325 )
                           );
    selectedItemIndex = 0;
}

MainMenu::~MainMenu()
{
    //dtor
}

void MainMenu::draw(sf::RenderWindow &window)
{
    //The start menu image
    sf::Texture menuTexture_Start;
    menuTexture_Start.loadFromFile("assets/menus/mainmenu.jpg");
    sf::Sprite menuObject_Start(menuTexture_Start);
    window.draw(menuObject_Start);
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
        window.draw(menuText[i]);
}
