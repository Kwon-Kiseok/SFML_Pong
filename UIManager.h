#pragma once
#include "SFML/Graphics.hpp"
#include "Singleton.h"

using namespace sf;

class UIManager : public Singleton<UIManager>
{
private:
	Text textMessage;
	Text textScore;
	Font fontDSDIGI;
	FloatRect textRect;

	int score = 0;
public:
	void Init();
	void SetRect();
	void Update();
	void SetScore(int add);
	int GetScore();
	void DrawScore(RenderWindow* window);
	void DrawMessage(RenderWindow* window);
};

