#include "Ball.h"
#include <cmath>
#include <iostream>

Ball::Ball()
{
}

Ball::Ball(float x, float y)
	:Object(x, y), originPos(x, y)
{
	dir.x = 1.f;
	dir.y = -1.f;
	
	// 단위벡터로 노말라이즈
	float length = sqrt(dir.x * dir.x + dir.y * dir.y);
	dir.x /= length;
	dir.y /= length;


	shape.setSize(Vector2f(10, 10));
	//shape.setPosition(position);
	shape.setFillColor(Color::White);
}

Ball::~Ball()
{
}

Ball::Ball(const Ball& copy)
	:Object(copy), originPos(copy.originPos), speed(copy.speed), dir(copy.dir)
{
}

Ball& Ball::operator=(const Ball& ref)
{
	Object::operator=(ref);
	originPos = ref.originPos;
	speed = ref.speed;
	dir = ref.dir;
	return *this;
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

void Ball::SetXY(float x, float y)
{
	position.x = x;
	position.y = y;
}

void Ball::Update(float dt)
{
	position += dir * dt * speed;
	shape.setPosition(position);
}
