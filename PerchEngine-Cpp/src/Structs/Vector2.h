#pragma once

#ifdef PERCHENGINECPP_EXPORTS
#define PERCH_API __declspec(dllexport)
#else
#define PERCH_API __declspec(dllimport)
#endif


#include <SDL.h>

#include "Vector2i.h"

#include <memory>
#include <string>

namespace Perch
{

	/// <summary>
	/// 
	/// </summary>
	struct Vector2
	{

	public:
		float x = 0;
		float y = 0;


	public:

		PERCH_API Vector2();
		PERCH_API Vector2(float x, float y);
		PERCH_API Vector2(float val);

		PERCH_API inline static Vector2 Zero() { return Vector2(); }
		PERCH_API inline static Vector2 One() { return Vector2(1.f, 1.f); }
		PERCH_API inline static Vector2 Half() { return Vector2(0.5f, 0.5f); }
		PERCH_API inline static Vector2 Left() { return Vector2(0.f, 0.5f); }
		PERCH_API inline static Vector2 Right() { return Vector2(1.f, 0.5f); }
		PERCH_API inline static Vector2 Up() { return Vector2(0.5f, 0.0f); }
		PERCH_API inline static Vector2 Down() { return Vector2(0.5f, 1.0f); }
		PERCH_API inline static Vector2 TopLeft() { return Vector2(); }
		PERCH_API inline static Vector2 TopRight() { return Vector2(1.f, 0.f); }
		PERCH_API inline static Vector2 BottomLeft() { return Vector2(0.f, 1.f); }
		PERCH_API inline static Vector2 BottomRight() { return Vector2(1.f, 1.f); }

		PERCH_API float Magnitude() const;

		PERCH_API float Dot(Vector2 const& other) const;
		PERCH_API float Distance(Vector2 const& other) const;

		PERCH_API void Normalize();
		PERCH_API Vector2 NormalizedVector() const;

		PERCH_API Vector2 Midpoint(Vector2 const& other) const;
		PERCH_API Vector2 ProportionalPoint(Vector2 const& other, float proportion) const;

		PERCH_API std::shared_ptr<SDL_Point> GetSDLPoint() const;

		PERCH_API operator Vector2i() const;

		PERCH_API Vector2 operator+(Vector2 const& other);
		PERCH_API Vector2& operator+=(Vector2 const& other);
		PERCH_API Vector2 operator-(Vector2 const& other);
		PERCH_API Vector2& operator-=(Vector2 const& other);
		PERCH_API Vector2 operator*(Vector2 const& other);
		PERCH_API Vector2& operator*=(Vector2 const& other);
		PERCH_API Vector2 operator/(Vector2 const& other);
		PERCH_API Vector2& operator/=(Vector2 const& other);

		PERCH_API Vector2 operator+(float const& other);
		PERCH_API Vector2& operator+=(float const& other);
		PERCH_API Vector2 operator-(float const& other);
		PERCH_API Vector2& operator-=(float const& other);
		PERCH_API Vector2 operator*(float const& other);
		PERCH_API Vector2& operator*=(float const& other);
		PERCH_API Vector2 operator/(float const& other);
		PERCH_API Vector2& operator/=(float const& other);

		PERCH_API bool operator==(const Vector2& other);
		PERCH_API bool operator!=(const Vector2& other);

		PERCH_API std::string ToString();

	};

}
