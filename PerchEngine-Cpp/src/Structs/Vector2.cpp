#include "pch.h"

#include "Vector2.h"
#include "../Squawk/Log.h"
#include <cmath>

using namespace std;
using namespace Squawk;
using namespace Perch;

Vector2::Vector2()
{
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(float val)
{
	x = y = val;
}

float Vector2::Magnitude() const
{
	return sqrtf(x * x + y * y);
}

float Vector2::Dot(Vector2 const& other) const
{
	return x * other.x + y * other.y;
}

float Vector2::Distance(Vector2 const& other) const
{
	Vector2 current = *this;
	return (current - other).Magnitude();
}

void Vector2::Normalize()
{
	float magnitude = Magnitude();
	x /= magnitude;
	y /= magnitude;
}

Vector2 Vector2::NormalizedVector() const
{
	Vector2 current = *this;
	current.Normalize();
	return current;
}

Vector2 Vector2::Midpoint(Vector2 const& other) const
{
	return ProportionalPoint(other, 0.5f);
}

Vector2 Vector2::ProportionalPoint(Vector2 const& other, float proportion) const
{
	return Vector2((x + other.x) * proportion, (y + other.y) * proportion);
}

shared_ptr<SDL_Point> Vector2::GetSDLPoint() const
{
	SDL_Point* sdlPoint = new SDL_Point();
	sdlPoint->x = x + 0.5f;
	sdlPoint->y = y + 0.5f;
	return shared_ptr<SDL_Point>(sdlPoint);
}






Vector2::operator Vector2i() const
{
	return Vector2i(x, y);
}

Vector2 Vector2::operator+(Vector2 const& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2& Vector2::operator+=(Vector2 const& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2 Vector2::operator-(Vector2 const& other)
{
	return Vector2(x - other.x, y - other.y);
}

Vector2& Vector2::operator-=(Vector2 const& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2 Vector2::operator*(Vector2 const& other)
{
	return Vector2(x * other.x, y * other.y);
}

Vector2& Vector2::operator*=(Vector2 const& other)
{
	x *= other.x;
	y *= other.y;
	return *this;
}

Vector2 Vector2::operator/(Vector2 const& other)
{
	return Vector2(x / other.x, y / other.y);
}

Vector2& Vector2::operator/=(Vector2 const& other)
{
	x /= other.x;
	y /= other.y;
	return *this;
}

Vector2 Vector2::operator+(float const& other)
{
	return Vector2(x + other, y + other);
}

Vector2& Vector2::operator+=(float const& other)
{
	x += other;
	y += other;
	return *this;
}

Vector2 Vector2::operator-(float const& other)
{
	return Vector2(x - other, y - other);
}

Vector2& Vector2::operator-=(float const& other)
{
	x -= other;
	y -= other;
	return *this;
}

Vector2 Vector2::operator*(float const& other)
{
	return Vector2(x * other, y * other);
}

Vector2& Vector2::operator*=(float const& other)
{
	x *= other;
	y *= other;
	return *this;
}

Vector2 Vector2::operator/(float const& other)
{
	return Vector2(x / other, y / other);
}

Vector2& Vector2::operator/=(float const& other)
{
	x /= other;
	y /= other;
	return *this;
}

bool Vector2::operator==(const Vector2& other)
{
	return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2& other)
{
	return x != other.x && y != other.y;
}

string Vector2::ToString()
{
	char* s = Log::ToString("(%f, %f)", x, y);
	string str(s);
	free(s);
	return str;
}
