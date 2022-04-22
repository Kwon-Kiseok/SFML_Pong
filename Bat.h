#pragma once
#include "Object.h"
// �׸���: RectangleShape 
// �̵�
	// ����, ������
	// �ӵ�, �ð�

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

