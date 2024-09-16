#pragma once

#ifdef PERCHENGINECPP_EXPORTS
#define PERCH_API __declspec(dllexport)
#else
#define PERCH_API __declspec(dllimport)
#endif


#include <SDL.h>

#include "Vector2.h"
#include "Vector2i.h"

#include <memory>
#include <string>

namespace Perch
{

	/// <summary>
	/// 
	/// </summary>
	struct Rect2
	{

	private:

		Vector2 position = Vector2();
		Vector2 size = Vector2();
		// SDLRect is cached here because it is almost always used
		std::shared_ptr<SDL_Rect> sdlRect = std::shared_ptr<SDL_Rect>(new SDL_Rect);

	public:

		PERCH_API inline std::shared_ptr<SDL_Rect> GetSDLRect() { return sdlRect; }

	private:

		void UpdateSDLRect();

	public:

		PERCH_API Rect2();
		PERCH_API Rect2(Vector2 position, Vector2 size);
		PERCH_API Rect2(float x, float y, float w, float h);
		PERCH_API static std::shared_ptr<SDL_Rect> CreateSDLRect(Vector2 position, Vector2 size);

		PERCH_API Vector2 GetPosition();
		PERCH_API Vector2 GetSize();
		PERCH_API void SetPosition(Vector2 position);
		PERCH_API void SetPosition(Vector2i position);
		PERCH_API void SetPosition(float x, float y);
		PERCH_API void SetSize(Vector2 size);
		PERCH_API void SetSize(Vector2i size);
		PERCH_API void SetSize(float w, float h);

		PERCH_API bool PointIsIn(Vector2 point) const;
		PERCH_API static bool PointIsIn(Vector2 point, Vector2 position, Vector2 size);

		PERCH_API std::string ToString();

	};


}
