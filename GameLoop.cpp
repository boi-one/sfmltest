#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "GameLoop.h"
#include "Player.h"

using namespace sf;

void GameLoop::Run()
{
    //frame setup
    static RenderWindow window(VideoMode(640, 480), "sfmlol", Style::Close | Style::Resize);
    Clock sfclock;
    float deltaTime;
    bool windowFocused = true;
    sf::View camera;


    //player setup
    Vector2f playerDimentions = Vector2f(50.f, 50.f);
    std::string texturePath = ".\\radioactive.png";
    RectangleShape player = Player::SetupPlayer(playerDimentions, texturePath);
    player.setPosition(sf::Vector2f(window.getSize().x * 0.5f, window.getSize().y * 0.9f));
    float speed = 300.f;

    RectangleShape object(sf::Vector2f(50.f, 50.f));
    sf::Texture objectTexture;
    objectTexture.loadFromFile("radioactive.png");

    window.setFramerateLimit(60);

    object.move(50.f, 50.f);

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

            if (Keyboard::isKeyPressed(Keyboard::Key::A))
                player.move(-1.f * (deltaTime * speed), 0.0f);
            if (Keyboard::isKeyPressed(Keyboard::Key::D))
                player.move(1.f * (deltaTime * speed), 0.0f);
        
            camera.setCenter(player.getOrigin());
        }





        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos = Mouse::getPosition(window);
            object.setPosition((float)mousePos.x, (float)mousePos.y);
        }

        window.clear();
        
        player.setTexture(&objectTexture);
        window.draw(object);
        window.display();
        std::cout << deltaTime << std::endl;
    }
}
