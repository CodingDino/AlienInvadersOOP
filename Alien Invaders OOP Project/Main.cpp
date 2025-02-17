#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode()), "Alien Invaders",sf::State::Windowed);

    // Create player
    Player* player = new Player({ 500.0f,500.0f });

    // Clock for managing delta time
    sf::Clock gameTime;

    while (window.isOpen())
    {
        // Window events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        // Update
        float frameTime = gameTime.restart().asSeconds();
        player->Update(frameTime);


        // Drawing
        window.clear();
        

        // Draw all the things
        player->DrawTo(window);


        window.display();
    }


    delete player;
}