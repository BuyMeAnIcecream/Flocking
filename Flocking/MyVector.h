#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace sf;
class MyVector :public sf::Vector2f {
public:
	 using Vector2f::Vector2f;
	
	 Vector2f& limit(float scale);

	/* MyVector& normalize();

	 MyVector& rotateBy(float degrees, const MyVector& center = MyVector());

	 float getAngle();

	 float getLength();*/
};