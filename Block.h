#pragma once
#include "Object.h"

class Block : public Object
{
public:
	Block();
	~Block();
	Block(float x, float y, Color color);
	Block(const Block& copy);
	Block& operator=(const Block& ref);
};

