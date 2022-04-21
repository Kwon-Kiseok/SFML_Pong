#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Ball
{
private:
	Vector2f originPos;
	Vector2f position;
	RectangleShape shape;

	float speed = 500.f;
	Vector2f dir;

public:
	Ball(float x, float y);
	~Ball();

	FloatRect GetGlobalBounds();
	const RectangleShape& GetShape();

	void ReboundSides();
	void ReboundBatOrTop();
	void ReboundBottom();

	void Update(float dt);
};

