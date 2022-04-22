#pragma once
#include "SFML/Graphics.hpp"
#include "Singleton.h"

using namespace sf;

class UIManager : public Singleton<UIManager>
{
private:
	Text textMessage;
	Text textScore;
	Text textLife;
	Font fontDSDIGI;
	FloatRect textRect;

	int score = 0;
	int life = 0;
public:
	void Init();
	void SetRect();
	void Update();
	void SetScore(int add);
	int GetScore();
	void SetLife(int add);
	int GetLife();
	void DrawScore(RenderWindow* window);
	void DrawMessage(RenderWindow* window);
	void DrawLife(RenderWindow* window);
	Text& SetTextMessage(const char* str, int size, Color color);
};

