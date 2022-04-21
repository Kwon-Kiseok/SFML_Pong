#include "Block.h"

Block::Block()
{
}

Block::~Block()
{
}

Block::Block(float x, float y)
	:Object(x, y)
{
	shape.setSize(Vector2f(100, 30));
	shape.setFillColor(Color::Red);
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
