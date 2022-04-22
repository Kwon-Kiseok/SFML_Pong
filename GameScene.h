#pragma once
#include "Scene.h"

#define COL 9
#define ROW 5

class Bat;
class Ball;
class GameScene : public Scene
{
private:
	Bat* bat;
	Ball* ball;
	sf::Clock clock;
	bool isPause;
	int totalScore = 0;
public:
	GameScene() : bat(nullptr), ball(nullptr), isPause(true) {}
	~GameScene() {}

	virtual void Init();
	virtual void Update(sf::RenderWindow* window);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Clear();
};

