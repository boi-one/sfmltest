#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
	void Render(sf::Window& window,sf::Shape& object);
	void Render(sf::Window& window, sf::Shape& object, sf::Texture& texture);
};

