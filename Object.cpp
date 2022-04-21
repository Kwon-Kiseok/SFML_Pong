#include "Object.h"

Object::Object()
{
}

Object::Object(float x, float y)
	:position(x, y)
{
	shape.setPosition(position);
}

Object::Object(const Object& copy)
	:position(copy.position), shape(copy.shape)
{
}

Object& Object::operator=(const Object& ref)
{
	position = ref.position;
	shape = ref.shape;
	return *this;
}

FloatRect Object::GetGlobalBounds()
{
	return shape.getGlobalBounds();
}

const RectangleShape& Object::GetShape()
{
	return shape;
}
