#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	sf::RectangleShape body;
	sf::Texture texture;

public:
	Entity(sf::RectangleShape& body, sf::Vector2f& dimensions, std::string& texturePath);

	sf::RectangleShape Setup(sf::Vector2f& dimentions);
	void Render(sf::RenderWindow& window);
};
