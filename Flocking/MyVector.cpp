#include "MyVector.h"
/*
MyVector & MyVector::normalize()
{
		float length = (float)(x*x + y*y);
		if (length == 0.f)
			return *this;
		length = sqrt(1.f / length);
		x = (x * length);
		y = (y * length);
		return *this;

	// TODO: insert return statement here
}

float MyVector::getLength()
{
	return sqrt(x*x + y*y);
}




MyVector& MyVector::rotateBy(float degrees, const MyVector& center = MyVector())
{
	degrees *= 3.14159f / 180.f;
	const float cs = cos(degrees);
	const float sn = sin(degrees);

	x -= center.x;
	y -= center.y;

	float nx = x*cs - y*sn;
	float ny = x*sn + y*cs;

	x = nx;
	y = ny;

	x += center.x;
	y += center.y;
	return *this;
}


// returns trig angle

float MyVector:: getAngle()
{
	if (y == 0)
		return x < 0 ? 180 : 0;
	else if (x == 0)
		return y < 0 ? 270 : 90;

	if (y > 0)
		if (x > 0)
			return atan(y / x) * 180.f / 3.14159f;
		else
			return 180.0 - atan(y / -x) * 180.f / 3.14159f;
	else
		if (x > 0)
			return 360.0 - atan(-y / x) * 180.f / 3.14159f;
		else
			return 180.0 + atan(-y / -x) * 180.f / 3.14159f;
}

float MyVector::getLength()
{
	return sqrt(x*x + y*y);
}


MyVector& MyVector::limit(float scale)
{
	float length = getLength();
	if (length > scale)
	{
		float ratio = scale / length;
		x *= ratio;
		y *= ratio;
	}
	return *this;
}
*/