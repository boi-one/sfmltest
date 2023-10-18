#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "GameLoop.h"
#include "Entity.h"
#include "Player.h"

using namespace sf;

void GameLoop::Run()
{
    //frame setup
    RenderWindow window(VideoMode(640, 480), "sfmlol", Style::Close | Style::Resize);
    View view(Vector2f(0.f, 0.f), Vector2f(512.f, 512.f));
    uint16_t screenWidth = window.getSize().x;
    uint16_t screenHeight = window.getSize().y;
    Clock sfclock;
    float deltaTime;
    bool windowFocused = true;
    sf::View camera;
    std::cout << screenWidth << " " << screenHeight << std::endl;
    window.setFramerateLimit(60);

    RectangleShape playerBody;
    Entity* player = new Entity(playerBody, sf::Vector2f(150.f, 150.f));

    RectangleShape object(sf::Vector2f(50.f, 50.f));
    sf::Texture objectTexture;
    objectTexture.loadFromFile("radioactive.png");
    
    //update loop
    while (window.isOpen())
    {
        //window events
        Event sfevent;
        while (window.pollEvent(sfevent))
        {
            switch (sfevent.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                std::cout << "Window width " << sfevent.size.width << " Window height " << sfevent.size.height << std::endl;
                break;
            case Event::GainedFocus:
                    windowFocused = true;
                    break;
            case Event::LostFocus:
                windowFocused = false;
                break;
            }
        }
        if (windowFocused)
        {
            deltaTime = sfclock.restart().asSeconds();

           // player->MovePlayer(deltaTime);
        }
        window.clear();
        //window.setView(view);
        player->Render(window);
        window.display();


        //std::cout << "MousePos: X: " << Mouse::getPosition().x << " Y: " << Mouse::getPosition().y << std::endl;
        //std::cout << "X: " << player.getPosition().x << " Y: " << player.getPosition().y << std::endl;
        //std::cout << deltaTime << std::endl;
    }
}
