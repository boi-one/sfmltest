#pragma once
#include <SFML/Graphics.hpp>

class Player : Entity
{
public:
	static sf::RectangleShape SetupPlayer(sf::Vector2f& dimentions);
	static sf::RectangleShape SetupPlayer(sf::Vector2f& dimentions, std::string& texturePath);
	static void MovePlayer(sf::RectangleShape& player, float& speed, float& deltaTime);
};