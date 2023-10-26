#include "Entity.h"
#include "Player.h"
#include <iostream>
using namespace sf;

Player::Player(sf::RectangleShape& body, sf::Vector2f& dimentions, std::string& texturePath, float& movementSpeed) : Entity(body, dimentions, texturePath), movementSpeed(movementSpeed)
{
	spriteFacingLeft = false;
}

void Player::MovePlayer(float& deltaTime)
{

	if (Keyboard::isKeyPressed(Keyboard::Key::A))
	{
		spriteFacingLeft = true;
		if (spriteFacingLeft)
		{
			this->body.setScale(-1.f, 1.f);
			spriteFacingLeft = false;
		}
		body.move(-1.f * (movementSpeed * deltaTime), 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D))
	{
		spriteFacingLeft = false;
		if(!spriteFacingLeft)
		{
			this->body.setScale(1.f, 1.f);
			spriteFacingLeft = true;
		}
		body.move(1.f * (movementSpeed * deltaTime), 0.f);
	}
}
