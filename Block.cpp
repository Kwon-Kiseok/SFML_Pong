#include "Block.h"

Block::Block()
{
}

Block::~Block()
{
}

Block::Block(float x, float y, Color color)
	:Object(x, y)
{
	shape.setSize(Vector2f(200, 50));
	shape.setFillColor(color);
}

Block::Block(const Block& copy)
	:Object(copy)
{
}

Block& Block::operator=(const Block& ref)
{
	Object::operator=(ref);
	return *this;
}

void Block::Update()
{

}
