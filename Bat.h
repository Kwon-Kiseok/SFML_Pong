#pragma once
#include "SFML/Graphics.hpp"
// 그리기: RectangleShape 
// 이동
	// 왼쪽, 오른쪽
	// 속도, 시간

using namespace sf;

enum class Sides
{
	LEFT,
	RIGHT,
	NONE
};

class Bat
{
private:
	Vector2f position;
	RectangleShape shape;
	float speed = 1000.f;
	Sides moveDir = Sides::NONE;

public:
	Bat(float x, float y);
	~Bat();

	FloatRect GetGlobalBounds();
	const RectangleShape& GetShape();

	void SetMoveDir(Sides side);
	void Update(float dt);
};

