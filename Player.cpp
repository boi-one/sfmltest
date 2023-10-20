#include "Entity.h"
#include "Player.h"
#include <iostream>
using namespace sf;

Player::Player(sf::RectangleShape& body, sf::Vector2f& dimentions, std::string& texturePath, float& movementSpeed) : Entity(body, dimentions, texturePath), movementSpeed(movementSpeed)
{
	std::cout << "player initialized " << body.getPosition().x  << ' ' << body.getPosition().y << std::endl;
}

void Player::MovePlayer(float& deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::A))
		body.move(-1.f * (movementSpeed * deltaTime), 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key::D))
		body.move(1.f * (movementSpeed * deltaTime), 0.f);
}
