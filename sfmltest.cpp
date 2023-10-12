#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
    //SFML SCREEN COORDINATES////////////////////////\\
    // 0, 0                           screenwidth, 0 \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    // 0, screenheight     screenwidth, screenheigth \\
    //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    sf::RenderWindow window(sf::VideoMode(640, 480), "sfmlol", sf::Style::Close | sf::Style::Resize);
   
    sf::RectangleShape = Player::SetupPlayer(sf::Vector2f(50.f, 50.f), );

    while (window.isOpen())
    {
        sf::Event sfevent;
        while (window.pollEvent(sfevent))
        {
            switch (sfevent.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "Window width " << sfevent.size.width << " Window height " << sfevent.size.height << std::endl;
                break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            player.move(0.0f, -0.1f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.move(-0.1f, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            player.move(0.0f, 0.1f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.move(0.1f, 0.0f);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            player.setPosition((float)mousePos.x, (float)mousePos.y);
        }

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}