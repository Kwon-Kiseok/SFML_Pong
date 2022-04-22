#include "Bat.h"


Bat::Bat()
{
}

Bat::~Bat()
{
}

Bat::Bat(float x, float y)
	:Object(x, y)
{
	shape.setSize(Vector2f(100, 10));
	shape.setFillColor(Color::White);
}

Bat::Bat(const Bat& copy)
	:Object(copy), speed(copy.speed), moveDir(copy.moveDir)
{
}

Bat& Bat::operator=(const Bat& ref)
{
	Object::operator=(ref);
	speed = ref.speed;
	moveDir = ref.moveDir;
	return *this;
}

void Bat::SetMoveDir(Sides side)
{
	moveDir = side;
}

void Bat::SetSize(float add)
{
	shape.setSize(Vector2f(shape.getSize().x + add, shape.getSize().y));
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
