#pragma once
#include "Object.h"

class Ball : public Object
{
private:
	Vector2f originPos;

	float speed = 500.f;
	Vector2f dir;

public:
	Ball();
	Ball(float x, float y);
	~Ball();
	Ball(const Ball& copy);
	Ball& operator=(const Ball& ref);

	void ReboundSides();
	void ReboundBatOrTop();
	void ReboundBottom();
	void SetXY(float x, float y);
	void Update(float dt);
};

