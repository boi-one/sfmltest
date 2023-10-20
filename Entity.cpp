#include "Entity.h"
#include <iostream>

Entity::Entity(sf::RectangleShape& body, sf::Vector2f& dimensions, std::string& texturePath) : body(body)
{
	body.setSize(dimensions);
	body.setOrigin(body.getScale().x * 0.5f, body.getScale().y * 0.5f);
	
	texture.loadFromFile(texturePath);
}

void Entity::Render(sf::RenderWindow& window)
{
	body.setTexture(&texture);
	window.draw(body);
}


