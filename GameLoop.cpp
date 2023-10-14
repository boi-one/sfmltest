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
    static RenderWindow window(VideoMode(640, 480), "sfmlol", Style::Close | Style::Resize);
    Clock sfclock;
    float deltaTime;
    bool windowFocused = true;
    sf::View camera;


    //player setup
    Vector2f playerDimentions = Vector2f(150.f, 150.f);
    RectangleShape player = Player::SetupPlayer(playerDimentions);
    player.setPosition(sf::Vector2f(window.getSize().x * 0.5f, window.getSize().y * 0.6f));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("gorillafromgorillagrill.png");
    float speed = 300.f;
    bool flipped = false;
        //jump setup
    bool spaceKey = false;
    bool inAir = false;
    float startSpeed = 0;
    sf::Vector2f velocity;
    float gravitationalForce;
    sf::Vector2f gravity;
    float time = 0;



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


            //player movement
            if (Keyboard::isKeyPressed(Keyboard::Key::A))
            {
                if (!flipped)
                {
                    player.setScale(-player.getScale().x, player.getScale().y);
                    flipped = true;
                }
                player.move(-1.f * (deltaTime * speed), 0.0f);
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::D))
            {
                if (flipped)
                {
                    player.setScale(-player.getScale().x, player.getScale().y);
                    flipped = false;
                }
                player.move(1.f * (deltaTime * speed), 0.0f);
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Space))
                spaceKey = true;
            else
                spaceKey = false;
            Player::Jump(player, deltaTime, spaceKey, inAir, startSpeed, velocity, gravitationalForce, gravity, time);
            camera.setCenter(player.getOrigin());
        }





        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos = Mouse::getPosition(window);
            object.setPosition((float)mousePos.x, (float)mousePos.y);
        }

        window.clear();
        Entity::Render(window, player, playerTexture);
        Entity::Render(window, object, objectTexture);
        window.display();


        std::cout << "X: " << player.getPosition().x << " Y: " << player.getPosition().y << std::endl;
        //std::cout << deltaTime << std::endl;
    }
}
