#include "Entity.h"

class Entity
{
public:
	sf::RectangleShape body;
	sf::Texture texture;

	explicit Entity(sf::RectangleShape& body, sf::Vector2f& dimentions, std::string& texturePath)
	{
		body = this->body;
		body.setOrigin(body.getScale().x * 0.5f, body.getScale().y * 0.5f);
		texture.loadFromFile(texturePath);
	}

	void Render(sf::RenderWindow& window)
	{
		window.draw(this->body);
		this->body.setTexture(&texture);
	}

};


