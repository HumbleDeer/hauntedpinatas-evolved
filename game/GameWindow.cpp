#include <SFML/Graphics.hpp>
#include "GameWindow.hpp"

//Variables available to GameWindow class in general.
GameWindow::GameWindow(void)
{
    PlayerSpeed = 0.45;

    //Setting sprite
    //RoomTexture.loadFromFile("/textures/room.jpg");
    PlayerStaticTexture[0].loadFromFile("assets/sprites/player/playersprite_back.png");
    PlayerStaticTexture[1].loadFromFile("assets/sprites/player/playersprite_left.png");
    PlayerStaticTexture[2].loadFromFile("assets/sprites/player/playersprite_right.png");
    PlayerStaticTexture[3].loadFromFile("assets/sprites/player/playersprite_front.png");

    PlayerSprite.setTexture(PlayerStaticTexture[0]);
    PlayerSprite.setColor(sf::Color(255,255,255,255));

}

int GameWindow::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;

    PlayerSprite.setPosition((App.getSize().x/2)-PlayerSprite.getGlobalBounds().width/2,(App.getSize().y/4)*3);

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
                case sf::Keyboard::W:
                    moveUp = true;
                    /*moveDown = false;*/
                    moveLeft = false;
                    moveRight = false;
                    PlayerSprite.setTexture(PlayerStaticTexture[0]);
                    std::cout << "Move up: " << moveUp <<std::endl;
                    break;
                case sf::Keyboard::S:
                    /*moveUp = false;*/
                    moveDown = true;
                    moveLeft = false;
                    moveRight = false;
                    PlayerSprite.setTexture(PlayerStaticTexture[3]);
                    std::cout << "Move down: " << moveDown <<std::endl;
                    break;
                case sf::Keyboard::A:
                    moveUp = false;
                    moveDown = false;
                    moveLeft = true;
                    /*moveRight = false;*/
                    PlayerSprite.setTexture(PlayerStaticTexture[1]);
                    std::cout << "Move left: " << moveLeft <<std::endl;
                    break;
                case sf::Keyboard::D:
                    moveUp = false;
                    moveDown = false;
                    /*moveLeft = false;*/
                    moveRight = true;
                    PlayerSprite.setTexture(PlayerStaticTexture[2]);
                    std::cout << "Move right: " << moveRight <<std::endl;
                    break;
                default:
                    break;
                }
            }
            if (Event.type == sf::Event::KeyReleased)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::W:
                    moveUp = false;
                    std::cout << "Move up: " << moveUp <<std::endl;
                    break;
                case sf::Keyboard::S:
                    moveDown = false;
                    std::cout << "Move down: " << moveDown <<std::endl;
                    break;
                case sf::Keyboard::A:
                    moveLeft = false;
                    std::cout << "Move left: " << moveLeft <<std::endl;
                    break;
                case sf::Keyboard::D:
                    moveRight = false;
                    std::cout << "Move right: " << moveRight <<std::endl;
                    break;
                default:
                    break;
                }
            }
        }

        if(moveUp && !(moveLeft || moveRight))
        {
            PlayerSprite.move(
                0.0f * PlayerSpeed,
                -0.1f * PlayerSpeed
            );
        }
        if(moveDown && !(moveLeft || moveRight))
        {
            PlayerSprite.move(
                0.0f * PlayerSpeed,
                0.1f * PlayerSpeed
            );
        }
        if(moveLeft && !(moveUp || moveDown))
        {
            PlayerSprite.move(
                -0.1f * PlayerSpeed,
                0.0f * PlayerSpeed
            );
        }
        if(moveRight && !(moveUp || moveDown))
        {
            PlayerSprite.move(
                0.1f * PlayerSpeed,
                0.0f * PlayerSpeed

            );
        }

        //Clearing screen
        App.clear(sf::Color(0, 0, 0, 0));
        //Drawing
        App.draw(PlayerSprite);
        App.display();
    }

//Never reaching this point normally, but just in case, exit the application
    return -1;
}
