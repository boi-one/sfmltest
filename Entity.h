#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	sf::RectangleShape body;
	std::string texturePath;
	sf::Texture texture;

public:
	Entity(sf::RectangleShape& body, sf::Vector2f& dimensions, std::string& texturePath);
	
	void Render(sf::RenderWindow& window);
};
