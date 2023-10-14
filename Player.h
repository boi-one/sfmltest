#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
public:
	static sf::RectangleShape SetupPlayer(sf::Vector2f& dimentions);
	static sf::RectangleShape SetupPlayer(sf::Vector2f& dimentions, std::string& texturePath);
	static void MovePlayer(sf::RectangleShape& player, float& speed, float& deltaTime);
	static void Jump(sf::RectangleShape& player, float& deltaTime, bool& spaceKey, bool& inAir, float& startSpeed, sf::Vector2f& velocity, const float& gravitationalForce, sf::Vector2f& gravity, float& time);
};