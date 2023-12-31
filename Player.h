#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
public:
	float movementSpeed;
	bool spriteFacingLeft;

public:
	Player(sf::RectangleShape& body, sf::Vector2f& dimentions, std::string& texturePath, float& movementSpeed);

	void MovePlayer(float& deltaTime);
	//void Jump(sf::RectangleShape& player, float& deltaTime, bool& spaceKey, bool& inAir, float& startSpeed, sf::Vector2f& velocity, const float& gravitationalForce, sf::Vector2f& gravity, float& time);
};
