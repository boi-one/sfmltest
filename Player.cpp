#include "Entity.h"
#include "Player.h"
#include <iostream>
using namespace sf;

class Player : public Entity
{	
public:
	float movementSpeed = 0;
	bool spriteFacingLeft = false;

	Player(sf::RectangleShape& body, sf::Vector2f& dimentions, std::string& texturePath) : Entity(body, dimentions, texturePath)
	{
		movementSpeed = this->movementSpeed;
	}

	void MovePlayer(float& deltaTime)
	{
		if(Keyboard::isKeyPressed(Keyboard::Key::A))
			body.move(-1.f * movementSpeed, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::Key::D))
			body.move(1.f * movementSpeed, 0.f);
	}

};
