#pragma once
#include "Scene.h"

class WinScene : public Scene
{
private:

public:
	WinScene() {}
	~WinScene() {}

	virtual void Init();
	virtual void Update(sf::RenderWindow* window);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Clear();
};

