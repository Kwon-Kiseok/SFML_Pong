#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
private:

public:
	TitleScene() {}
	~TitleScene() {}

	virtual void Init();
	virtual void Update(sf::RenderWindow* window);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Clear();
};

