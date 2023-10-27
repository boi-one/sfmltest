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
    View view(Vector2f(0.f, 0.f), Vector2f(640.f, 480.f));
    uint16_t screenWidth = window.getSize().x;
    uint16_t screenHeight = window.getSize().y;
    Clock sfclock;
    float deltaTime;
    bool windowFocused = true;
    sf::View camera;
    window.setFramerateLimit(60);

    //background setup
    sf::Texture background;
    background.loadFromFile("background.png");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    background.setRepeated(true);
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1500, 1500) /*window.getSize().x, window.getSize().y)*/);

    //player setup
    Vector2f dimensions = sf::Vector2f(150.f, 150.f);
    RectangleShape playerBody(dimensions);
    float playerMovementSpeed = 300.f;
    std::string playerTexturePath = "gorillafromgorillagrill.png";
    Player* player = new Player(playerBody, dimensions, playerTexturePath, playerMovementSpeed);
    player->body.setPosition(screenWidth * 0.5f, screenHeight * 0.65f);
    player->body.setOrigin(player->body.getScale().x * 0.5f, player->body.getScale().y * 0.5f);

    RectangleShape test(sf::Vector2f(50, 50));

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

            player->MovePlayer(deltaTime);
            view.setCenter(player->body.getPosition());
        }

        window.clear();
        window.setView(view);

        if (backgroundSprite.getPosition().x - player->body.getPosition().x > backgroundSprite.getScale().x * 0.5f)
        {
            backgroundSprite.setPosition(player->body.getPosition().x, backgroundSprite.getPosition().y);
        }

        window.draw(backgroundSprite);

        window.draw(test);
        test.setPosition(player->body.getPosition());
        player->Render(window);
        window.display();
    }
}
