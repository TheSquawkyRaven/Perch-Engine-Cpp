#include "pch.h"

#include "Rect2.h"
#include "../Squawk/Log.h"

using namespace Perch;
using namespace Squawk;
using namespace std;

void Rect2::UpdateSDLRect()
{
	sdlRect->x = (int)(position.x + 0.5f);
	sdlRect->y = (int)(position.y + 0.5f);
	sdlRect->w = (int)(size.x + 0.5f);
	sdlRect->h = (int)(size.y + 0.5f);
}

Rect2::Rect2()
{
	UpdateSDLRect();
}

Rect2::Rect2(Vector2 position, Vector2 size)
{
	SetPosition(position);
	SetSize(size);
}

Rect2::Rect2(float x, float y, float w, float h)
{
	SetPosition(x, y);
	SetSize(w, h);
}

shared_ptr<SDL_Rect> Rect2::CreateSDLRect(Vector2 position, Vector2 size)
{
	shared_ptr<SDL_Rect> rect = shared_ptr<SDL_Rect>(new SDL_Rect);
	rect->x = (int)(position.x + 0.5f);
	rect->y = (int)(position.y + 0.5f);
	rect->w = (int)(size.x + 0.5f);
	rect->h = (int)(size.y + 0.5f);

	return rect;
}

Vector2 Rect2::GetPosition()
{
	return Vector2(position.x, position.y);
}

Vector2 Rect2::GetSize()
{
	return Vector2(size.x, size.y);
}

void Rect2::SetPosition(Vector2 position)
{
	SetPosition(position.x, position.y);
}

void Rect2::SetPosition(Vector2i position)
{
	SetPosition(position.x, position.y);
}

void Rect2::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	UpdateSDLRect();
}

void Rect2::SetSize(Vector2 size)
{
	SetSize(size.x, size.y);
}

void Rect2::SetSize(Vector2i size)
{
	SetSize(size.x, size.y);
}

void Rect2::SetSize(float w, float h)
{
	size.x = w;
	size.y = h;
	UpdateSDLRect();
}

bool Rect2::PointIsIn(Vector2 point) const
{
	return PointIsIn(point, position, size);
}

bool Rect2::PointIsIn(Vector2 point, Vector2 position, Vector2 size)
{
	if (point.x < position.x)
	{
		// Point is Left
		return false;
	}
	if (point.x > position.x + size.x)
	{
		// Point is Right
		return false;
	}
	if (point.y < position.y)
	{
		// Point is Above
		return false;
	}
	if (point.y > position.y + size.y)
	{
		// Point is Below
		return false;
	}
	return true;
}

string Rect2::ToString()
{
	char* s = Log::ToString("[Pos%s, Size%s]", position.ToString().c_str(), size.ToString().c_str());
	string str(s);
	free(s);
	return str;
}
