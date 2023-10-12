#include "Player.h"

Player::SetupPlayer(sf::Vector2f& dimentions)
{
    sf::RectangleShape player(dimentions);
    player.setOrigin(player.getScale().x * 0.5f, player.getScale().y * 0.5f);

    return player;
}

Player::SetupPlayer(sf::Vector2f& dimentions, std::string& texturePath)
{
    sf::RectangleShape player(dimentions);
    player.setOrigin(player.getScale().x*0.5f, player.getScale().y * 0.5f);
    sf::Texture playerTexture;
    playerTexture.loadFromFile(texturePath);
    player.setTexture(&playerTexture);

    return player;
}
