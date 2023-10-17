#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	sf::RectangleShape body;
	sf::Texture texture;
	sf::RectangleShape Setup(sf::Vector2f& dimentions);
	void Render(sf::RenderWindow& window);
};

