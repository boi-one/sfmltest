#pragma once
#include <vector>
using namespace sf;

class GameLoop
{
public:
	static void Start();
	static void Run();
private:	
	std::vector<sf::Shape> renderShapes;
};

