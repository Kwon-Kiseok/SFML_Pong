#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Object
{
protected:
	Vector2f position;
	RectangleShape shape;

public:
	Object();
	Object(float x, float y);
	virtual ~Object() {};
	Object(const Object& copy);
	Object& operator=(const Object& ref);

	virtual FloatRect GetGlobalBounds();
	virtual const RectangleShape& GetShape();

};

