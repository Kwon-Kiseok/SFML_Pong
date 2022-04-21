#include "Ball.h"
#include <cmath>
#include <iostream>

Ball::Ball(float x, float y)
	:position(x, y), originPos(x, y)
{
	dir.x = 1.f;
	dir.y = 1.f;
	
	// 단위벡터로 노말라이즈
	float length = sqrt(dir.x * dir.x + dir.y * dir.y);
	dir.x /= length;
	dir.y /= length;


	shape.setSize(Vector2f(10, 10));
	shape.setPosition(position);
	shape.setFillColor(Color::White);
}

Ball::~Ball()
{
}

FloatRect Ball::GetGlobalBounds()
{
	return shape.getGlobalBounds();
}

const RectangleShape& Ball::GetShape()
{
	return shape;
}

void Ball::ReboundSides()
{
	dir.x *= -1.f;
}

void Ball::ReboundBatOrTop()
{
	dir.y *= -1.f;
}

void Ball::ReboundBottom()
{
	std::cout << position.y << std::endl;
	position = originPos;
}

void Ball::Update(float dt)
{
	position += dir * dt * speed;
	shape.setPosition(position);
}
