#pragma once
#include "Object.h"

class Block : public Object
{
public:
	Block();
	~Block();
	Block(float x, float y);
	Block(const Block& copy);
	Block& operator=(const Block& ref);

	void Update();
};
