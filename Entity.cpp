#include "Entity.h"

void Entity::Render(sf::RenderWindow& window, sf::Shape& object)
{
	window.draw(object);
}
void Entity::Render(sf::RenderWindow& window, sf::Shape& object, sf::Texture& texture)
{
	window.draw(object);
	object.setTexture(&texture);
}
