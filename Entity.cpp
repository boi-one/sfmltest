#include "Entity.h"
#include <iostream>

Entity::Entity(sf::RectangleShape& body, sf::Vector2f& dimensions, std::string& texturePath) : body(body), texture(), texturePath(texturePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		std::cout << "Failed to load texture: " << texturePath << std::endl;
	}
	else
		std::cout << "Loaded file correctly! " << std::endl;



	body.setSize(dimensions); //this does nothing
	std::cout << body.getSize().x << std::endl;
	body.setOrigin(body.getScale().x * 0.5f, body.getScale().y * 0.5f);
	texture.loadFromFile(texturePath);
	body.setTexture(&texture);
}

void Entity::Render(sf::RenderWindow& window)
{
	body.setTexture(&texture);
	window.draw(body);
}


