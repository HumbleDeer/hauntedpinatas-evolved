#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <SFML/Audio/Music.hpp>

#include <iostream>
#include "main.h"

int main()
{
    // Create the main window
    sf::RenderWindow pinatas(sf::VideoMode(700, 550), "Haunted Piñatas Evolved", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);


    //Gameplay variables
    double playerSpeed = 0.75; //Playerspeed multiplier

    //Player sprite
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/sprites/player/playersprite_back.png");
    sf::Sprite playerSprite(playerTexture);

    //The start menu image
    sf::Texture menuTexture_Start;
    menuTexture_Start.loadFromFile("assets/menus/menutexture-start.jpg");
    sf::Sprite menuObject_Start (menuTexture_Start);

    // Load the window icon
    sf::Image window_icon;
    window_icon.loadFromFile("assets/icon.png");
    pinatas.setIcon(24, 24, window_icon.getPixelsPtr());


    //Make sound objects
    // Declare a new music
    sf::Music music_Menu;
    sf::Music music_Game;
    // Open it from an audio file
    if (!music_Menu.openFromFile("assets/sound/titlescreen-music.ogg") || !music_Game.openFromFile("assets/sound/game-music.ogg"))
    {
        std::cout << "A sound file failed to load.";
    }
    music_Menu.play();
    music_Game.setLoop(true);

    std::cout << "Playerspeed multiplier is " << playerSpeed << "x\n";

    // Start the game loop
    while (pinatas.isOpen())
    {
        // Process events
        sf::Event gameEvent;
        while (pinatas.pollEvent(gameEvent))
        {
            switch (gameEvent.type)
            {
            case sf::Event::Closed:
                pinatas.close();
                break;
            case sf::Event::Resized:
                std::cout << "Event: Window Resize: " << gameEvent.size.width << "x" << gameEvent.size.height << "\n";
                break;
            case sf::Event::KeyPressed:
                if(gameEvent.key.code == sf::Keyboard::Key::Escape)
                {
                    std::cout << "Escape was pressed";
                    isPaused = !isPaused;
                    if(!isPaused)
                    {
                        music_Menu.stop();
                        music_Game.play();
                    }
                    else
                    {
                        music_Menu.play();
                        music_Game.pause();
                    }
                    break;
                }
            }
        }
        //Check for player input, move the sprite around. Ignore this when paused.
        if(!isPaused)
        {
            if(useArrowKeys)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                {
                    // Move up
                    playerSprite.move((playerSpeed * 0.0f), (playerSpeed * -0.1f));
                    playerTexture.loadFromFile("assets/sprites/player/playersprite_back.png");
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
                {
                    // Move down
                    playerSprite.move((playerSpeed * 0.0f), (playerSpeed * 0.1f));
                    playerTexture.loadFromFile("assets/sprites/player/playersprite_front.png");
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                {
                    // Move left
                    playerSprite.move((playerSpeed * -0.1f), (playerSpeed * 0.0f));
                    playerTexture.loadFromFile("assets/sprites/player/playersprite_left.png");
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                {
                    // Move right
                    playerSprite.move((playerSpeed * 0.1f), (playerSpeed * 0.0f));
                    playerTexture.loadFromFile("assets/sprites/player/playersprite_right.png");
                }
            }
            else
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                {
                    // Move up
                    playerSprite.move((playerSpeed * 0.0f), (playerSpeed * -0.1f));
                    playerTexture.loadFromFile("assets/sprites/player/playersprite_back.png");
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                {
                    // Move down
                    playerSprite.move((playerSpeed * 0.0f), (playerSpeed * 0.1f));
                    playerTexture.loadFromFile("assets/sprites/player/playersprite_front.png");
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                {
                    // Move left
                    playerSprite.move((playerSpeed * -0.1f), (playerSpeed * 0.0f));
                    playerTexture.loadFromFile("assets/sprites/player/playersprite_left.png");
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    // Move right
                    playerSprite.move((playerSpeed * 0.1f), (playerSpeed * 0.0f));
                    playerTexture.loadFromFile("assets/sprites/player/playersprite_right.png");
                }
            }
        }
        // Clear screen
        pinatas.clear();


        //Draw pause or game items
        if(isPaused)
        {
            pinatas.draw(menuObject_Start);
        }
        else
        {
            pinatas.draw(playerSprite);
        }
        // Update the window
        pinatas.display();
    }

    return EXIT_SUCCESS;
}
