#include "Player.h"
#include <iostream>
using namespace sf;

sf::RectangleShape Player::SetupPlayer(sf::Vector2f& dimentions)
{
    sf::RectangleShape player(dimentions);
    player.setOrigin(player.getScale().x * 0.5f, player.getScale().y * 0.5f);

    return player;
}
sf::RectangleShape Player::SetupPlayer(sf::Vector2f& dimentions, std::string& texturePath)
{
    sf::RectangleShape player(dimentions);
    player.setOrigin(dimentions.x*0.5f, dimentions.y * 0.5f);
    Player::Texture playerTexture;


    return player;
}
