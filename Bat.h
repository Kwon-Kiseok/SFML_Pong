#pragma once
#include "Object.h"
// 그리기: RectangleShape 
// 이동
	// 왼쪽, 오른쪽
	// 속도, 시간

enum class Sides
{
	LEFT,
	RIGHT,
	NONE
};

class Bat : public Object
{
private:
	float speed = 1000.f;
	Sides moveDir = Sides::NONE;

public:
	Bat();
	~Bat();
	Bat(float x, float y);
	Bat(const Bat& copy);
	Bat& operator=(const Bat& ref);
	void SetMoveDir(Sides side);
	void SetSize(float add);
	void Update(float dt);
};

