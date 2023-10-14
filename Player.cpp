#include "Player.h"
#include <iostream>
using namespace sf;

sf::RectangleShape Player::SetupPlayer(sf::Vector2f& dimentions)
{
    sf::RectangleShape player(dimentions);
    player.setOrigin(player.getScale().x * 0.5f, player.getScale().y * 0.5f);

    return player;
}
void Player::Jump(sf::RectangleShape& player, float& deltaTime, bool& spaceKey, bool& inAir, float& startSpeed, sf::Vector2f& velocity, const float& gravitationalForce, sf::Vector2f& gravity, float& time)
{
    //I have translated this code from an old Unity assignment to make it work in sfml
    if (spaceKey && !inAir)
    {
        velocity = sf::Vector2f(0, startSpeed);
        gravity = sf::Vector2f(0, -gravitationalForce);
        inAir = true;
    }
    if (inAir)
    {
        time += deltaTime;
        velocity += sf::Vector2f(gravitationalForce * deltaTime, gravitationalForce * deltaTime);
        float tempPlayerPosX = player.getPosition().x + player.getPosition().x * velocity.x * deltaTime;
        float tempPlayerPosY = player.getPosition().y + player.getPosition().y * velocity.y * deltaTime;
        player.setPosition(tempPlayerPosX, tempPlayerPosY);
        if (player.getPosition().y < -1.f) //-60 is waarschijnlijk jumpheight?
        {
            time = 0.f;
            float myCalc = 2 * startSpeed / gravitationalForce;
            inAir = false;
            player.setPosition(sf::Vector2f(player.getPosition().x, -1.f));
        }
    }
}
