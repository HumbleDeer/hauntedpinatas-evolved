#include "Mainmenu.h"

MainMenu::MainMenu(float width, float height)
{
    menuFont_Button.loadFromFile("assets/InformalRoman.ttf");
    menuFont_Title.loadFromFile("assets/ChillerStdRegular.ttf");
    menuFont_Text.loadFromFile("");

    menuText_Static = sf::Color(45,45,120);//Normal text colour
    menuText_Active = sf::Color(150,180,90);//Active/hover text colour

    menuTexture_Start.loadFromFile("assets/menus/mainmenu.jpg");

    //Help button
    menuText[0].setFont(menuFont_Button);
    menuText[0].setFillColor(sf::Color::White);
    menuText[0].setOutlineColor(menuText_Static);
    menuText[0].setOutlineThickness(2);
    menuText[0].setString("Help");
    menuText[0].setCharacterSize(52);
    menuText[0].setPosition(sf::Vector2f(
                                ((width / (MAX_NUMBER_OF_ITEMS)*0) + (width / (MAX_NUMBER_OF_ITEMS * 2)) *1) - (menuText[0].getLocalBounds().width / 2),
                                height / 1.325)
                           );

    //Play button
    menuText[1].setFont(menuFont_Button);
    menuText[1].setFillColor(sf::Color::White);
    menuText[1].setOutlineColor(menuText_Active);
    menuText[1].setOutlineThickness(2);
    menuText[1].setString("Play");
    menuText[1].setCharacterSize(48);
    menuText[1].setPosition(sf::Vector2f((width / 2) - (menuText[1].getLocalBounds().width / 2),
                                         height / 1.5)
                           );

    //Quit button
    menuText[2].setFont(menuFont_Button);
    menuText[2].setFillColor(sf::Color::White);
    menuText[2].setOutlineColor(menuText_Static);
    menuText[2].setOutlineThickness(2);
    menuText[2].setString("Quit");
    menuText[2].setCharacterSize(52);
    menuText[2].setPosition(sf::Vector2f(
                                ((width / (MAX_NUMBER_OF_ITEMS)*2) + (width / (MAX_NUMBER_OF_ITEMS * 2)) *1) - (menuText[2].getLocalBounds().width / 2),
                                height / 1.325 )
                           );
    selectedItemIndex = 1;
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

void MainMenu::moveLeft()
{
    if(selectedItemIndex - 1 >= 0)
    {
        menuText[selectedItemIndex].setOutlineColor(menuText_Static);
        selectedItemIndex--;
        menuText[selectedItemIndex].setOutlineColor(menuText_Active);
    }
};
void MainMenu::moveRight()
{
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menuText[selectedItemIndex].setOutlineColor(menuText_Static);
        selectedItemIndex++;
        menuText[selectedItemIndex].setOutlineColor(menuText_Active);
    }
};
