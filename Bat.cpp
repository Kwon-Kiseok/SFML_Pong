#include "Bat.h"

Bat::Bat(float x, float y)
	: position(x, y)
{
	shape.setSize(Vector2f(100, 5));
	shape.setPosition(position);
	shape.setFillColor(Color::White);
}

Bat::~Bat()
{
}

FloatRect Bat::GetGlobalBounds()
{
	return shape.getGlobalBounds();
}

const RectangleShape& Bat::GetShape()
{
	return shape;
}

void Bat::SetMoveDir(Sides side)
{
	moveDir = side;
}

void Bat::Update(float dt)
{
	Vector2f dir;
	switch (moveDir)
	{
	case Sides::LEFT:
		dir.x = -1.f;
		break;
	case Sides::RIGHT:
		dir.x = 1.f;
		break;
	}

	position += dir * dt * speed;

	if (position.x < 0.f)
		position.x = 0.f;
	else if (position.x + 100.f > 1920.f)
		position.x = 1920.f - 100.f;
	shape.setPosition(position);
}
