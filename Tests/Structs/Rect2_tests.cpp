#include "pch.h"

#include "../PerchEngine-Cpp/src/Structs/Rect2.h"
#include "../PerchEngine-Cpp/src/Squawk/Log.h"
#include "memory.h"

using namespace std;
using namespace Squawk;
using namespace Perch;

namespace Structs
{

	static bool EQ(Rect2 lhs, Rect2 rhs)
	{
		return lhs.GetPosition() == rhs.GetPosition() && lhs.GetSize() == rhs.GetSize();
	}

	static bool EQ(Vector2 lhs, Vector2 rhs)
	{
		return lhs == rhs;
	}

	class Rect2Test : public testing::Test
	{

	protected:

		struct PointIsInTest
		{
			Rect2 rect;
			Vector2 point;
			bool pointIsInRect;
		};

		void SetUp() override
		{
			for (int i = 0; i < 8; i++)
			{
				rTestCases[i] = Rect2(vTestCases[i], vTestCases1[i]);
			}
		}

		Vector2 vTestCases[8] = {
			Vector2(6, 2),
			Vector2(-5.5f, 3),
			Vector2(-62, 75),
			Vector2(54.24f, 64.2f),
			Vector2(534.14f, 65.21f),
			Vector2(-43.66f, 434.2f),
			Vector2(463575.8765f, 143565.87654f),
			Vector2(-5413469.1022f, -74204222.155f),
		};

		Vector2 vTestCases1[8] = {
			Vector2(9, 3),
			Vector2(-8.22f, -4),
			Vector2(-41, 59),
			Vector2(41.2f, 54.6765f),
			Vector2(-99.211f, 75.2f),
			Vector2(21.5f, 124.f),
			Vector2(1236688.2f, -553643.12f),
			Vector2(-5324.1566f, -654535.6433f)
		};

		Rect2 rTestCases[8] = {};

		PointIsInTest pTestCases[8] = {
			{ Rect2(), Vector2(), true },
			{ Rect2(), Vector2(0.001f, 0.001f), false },
			{ Rect2(0, 0, 1, 1), Vector2(1, 1), true },
			{ Rect2(0, 0, 1, 1), Vector2(0.5f, 0.5f), true },
			{ Rect2(0, 0, 1, 1), Vector2(0.f, -0.1f), false },
			{ Rect2(-23, 55, 42.4f, 0.1f), Vector2(4.1f, 55.05f), true },
			{ Rect2(-23, 55, 42.4f, 0.1f), Vector2(19.5f, 55.05f), false },
			{ Rect2(-23, 55, 42.4f, 0.1f), Vector2(19.4f, 55.f), true },
		};

	};

	TEST_F(Rect2Test, Basic)
	{
		Rect2 first = Rect2();
		ASSERT_EQ(first.GetPosition().x, 0);
		ASSERT_EQ(first.GetPosition().y, 0);
		ASSERT_EQ(first.GetSize().x, 0);
		ASSERT_EQ(first.GetSize().y, 0);

		Rect2 second = Rect2(Vector2(2.2f, -4.5f), Vector2(24.3f, 77.42f));
		ASSERT_EQ(second.GetPosition().x, 2.2f);
		ASSERT_EQ(second.GetPosition().y, -4.5f);
		ASSERT_EQ(second.GetSize().x, 24.3f);
		ASSERT_EQ(second.GetSize().y, 77.42f);

		Rect2 third = Rect2(-154.5f, 333, 152.1f, 55);
		ASSERT_EQ(third.GetPosition().x, -154.5f);
		ASSERT_EQ(third.GetPosition().y, 333);
		ASSERT_EQ(third.GetSize().x, 152.1f);
		ASSERT_EQ(third.GetSize().y, 55);
	}

	TEST_F(Rect2Test, Equality)
	{
		ASSERT_TRUE(EQ(Rect2(), Rect2()));

		ASSERT_TRUE(EQ(Rect2(4, 2, 15, 22), Rect2(4.f, 2.f, 15.f, 22.f)));
		ASSERT_TRUE(EQ(Rect2(7.2f, 999.4f, -152.f, 15.55f), Rect2(Vector2(7.2f, 999.4f), Vector2( - 152, 15.55f))));
		ASSERT_FALSE(EQ(Rect2(-2.f, 3.f, 15.2f, 656.5512f), Rect2(2, 3.f, 15.2f, -656.5512f)));
		ASSERT_FALSE(EQ(Rect2(-2.5f, 5.f, 11.2f, 66.2f), Rect2(Vector2(-2, 5.f), Vector2(11.2f, -66.2f))));
	}

	TEST_F(Rect2Test, Setters)
	{
		Rect2 rect = Rect2();
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2 second = vTestCases1[i];
			
			rect.SetPosition(first);
			rect.SetSize(second);
			ASSERT_TRUE(EQ(rect.GetPosition(), first));
			ASSERT_TRUE(EQ(rect.GetSize(), second));

			rect.SetPosition((Vector2i)second);
			rect.SetSize((Vector2i)first);
			ASSERT_EQ(rect.GetPosition().x, (int)second.x);
			ASSERT_EQ(rect.GetPosition().y, (int)second.y);
			ASSERT_EQ(rect.GetSize().x, (int)first.x);
			ASSERT_EQ(rect.GetSize().y, (int)first.y);

			rect.SetPosition(second.x, first.y);
			rect.SetSize(first.x, second.y);
			ASSERT_EQ(rect.GetPosition().x, second.x);
			ASSERT_EQ(rect.GetPosition().y, first.y);
			ASSERT_EQ(rect.GetSize().x, first.x);
			ASSERT_EQ(rect.GetSize().y, second.y);
		}
	}

	TEST_F(Rect2Test, PointIsIn)
	{
		for (int i = 0; i < 8; i++)
		{
			PointIsInTest pTest = pTestCases[i];
			Rect2 rect = pTest.rect;
			Vector2 point = pTest.point;

			bool result = rect.PointIsIn(point);
			bool expected = pTest.pointIsInRect;

			ASSERT_EQ(result, expected) << Log::ToString("Rect:%s, Point:%s", rect.ToString(), point.ToString());
		}
	}

	TEST_F(Rect2Test, SDLRect)
	{
		for (int i = 0; i < 8; i++)
		{
			Rect2 first = rTestCases[i];
			shared_ptr<SDL_Rect> result = first.GetSDLRect();

			ASSERT_EQ(result->x, (int)(first.GetPosition().x + 0.5f));
			ASSERT_EQ(result->y, (int)(first.GetPosition().y + 0.5f));
			ASSERT_EQ(result->w, (int)(first.GetSize().x + 0.5f));
			ASSERT_EQ(result->h, (int)(first.GetSize().y + 0.5f));
		}
	}

	TEST_F(Rect2Test, ToString)
	{
		for (int i = 0; i < 8; i++)
		{
			Rect2 first = rTestCases[i];
			ASSERT_EQ(first.ToString(), "[Pos" + first.GetPosition().ToString() + ", Size" + first.GetSize().ToString() + "]");
		}
	}

}