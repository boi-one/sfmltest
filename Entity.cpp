#include "Entity.h"

Entity::Entity(sf::RectangleShape& body, sf::Vector2f& dimensions, std::string& texturePath)
{
	body = this->body;
	body.setOrigin(body.getScale().x * 0.5f, body.getScale().y * 0.5f);
	texture.loadFromFile(texturePath);
}

void Entity::Render(sf::RenderWindow& window)
{
	window.draw(this->body);
	this->body.setTexture(&texture);
}


