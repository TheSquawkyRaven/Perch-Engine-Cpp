#pragma once

#ifdef PERCHENGINECPP_EXPORTS
#define PERCH_API __declspec(dllexport)
#else
#define PERCH_API __declspec(dllimport)
#endif

#include <string>

namespace Perch
{

	struct Vector2;

	/// <summary>
	/// 
	/// </summary>
	struct Vector2i
	{

	public:
		int x = 0;
		int y = 0;


	public:

		PERCH_API operator Vector2() const;

		PERCH_API Vector2i();
		PERCH_API Vector2i(int x, int y);
		PERCH_API Vector2i(int val);

		PERCH_API std::string ToString();

	};


}
