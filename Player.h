#pragma once
#include <SFML/Graphics.hpp>
namespace sf
{
	class Player
	{
		public RectangleShape SetupPlayer(sf::RectangleShape& player, sf::Vector2f& dimentions, std::string& texturePath);
	};
}

