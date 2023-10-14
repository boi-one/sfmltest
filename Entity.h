#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	static void Render(sf::RenderWindow& window,sf::Shape& object);
	static void Render(sf::RenderWindow& window, sf::Shape& object, sf::Texture& texture);
};

