#pragma once
#include "sfml/System.hpp"
#include "sfml//Main.hpp"
#include "math.h"

using namespace sf;

static float getVectorLength(Vector2f vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

static Vector2f getNormal(Vector2f vec)
{
	float length = getVectorLength(vec);
	if (length <= 0)
		return Vector2f(0, 0);

	return Vector2f(vec.x / length, vec.y / length);
}

static Vector2f limit(Vector2f vec, float scale)
{
	float lenth = getVectorLength(vec);
	if (lenth > scale)
	{
		float ratio = scale / lenth;
		vec.x *= ratio;
		vec.y *= ratio;
	}
	return vec;
}

static Vector2f getRandomVector(int scale)
{
	return Vector2f(rand() % scale, rand() % scale);
}

static Vector2f multiply(Vector2f vec, float scale)
{
	return Vector2f(vec.x * scale, vec.y * scale);
}

static Vector2f divide(Vector2f vec, float scale)
{
	return Vector2f(vec.x / scale, vec.y / scale);
}

static float dotProduct(Vector2f vec1, Vector2f vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;;
}

static float getVectorAngle(Vector2f vec1, Vector2f vec2)
{
	float vec1Length = getVectorLength(vec1);
	float vec2Length = getVectorLength(vec2);
	return acos(dotProduct(vec1, vec2) / vec1Length / vec2Length);
}

static float getDistance(Vector2f vec1, Vector2f vec2)
{
	return getVectorLength(Vector2f(vec1.x - vec2.x, vec1.y - vec2.y));
}

static Vector2f getNormalPoint(Vector2f predicLoc, Vector2f a, Vector2f b)
{
	if ((predicLoc.x < a.x || predicLoc.x > b.x) && predicLoc.x > 0)
		return b;
	if ((predicLoc.x < a.x || predicLoc.x > b.x) && predicLoc.x < 0)
		return a;

	Vector2f ab = getNormal(b - a);
	Vector2f ap = predicLoc - a;
	float dis = dotProduct(ap, ab);
	return a + multiply(ab, dis);
}