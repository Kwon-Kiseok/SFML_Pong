#pragma once
#include "SFML/Graphics.hpp"

class Scene
{
protected:

public:
	Scene() {}
	virtual ~Scene() {}

	virtual void Init() = 0;
	virtual void Update(sf::RenderWindow* window) = 0;
	virtual void Draw(sf::RenderWindow* window) = 0;
	virtual void Clear() = 0;
};