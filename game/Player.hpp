#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>


class Player{
    public:
        Player();
        virtual ~Player();
        Draw(sf::RenderWindow& window);
        Update();

    protected:

    private:
};

#endif // PLAYER_HPP
