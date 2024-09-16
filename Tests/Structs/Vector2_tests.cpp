#include "pch.h"

#include "../PerchEngine-Cpp/src/Structs/Vector2.h"
#include "../PerchEngine-Cpp/src/Squawk/Log.h"
#include "memory.h"

using namespace std;
using namespace Squawk;
using namespace Perch;

namespace Structs
{

	static bool EQ(Vector2 lhs, Vector2 rhs)
	{
		return lhs == rhs;
	}

	class Vector2Test : public testing::Test
	{

	protected:

		void SetUp() override
		{

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

		float fTestCases[8] = {
			2,
			-6.4f,
			42.1f,
			64.66f,
			2542.2565f,
			567.211f,
			494123.6664213f,
			3745215678.43543657f,
		};

	};

	TEST_F(Vector2Test, Basic)
	{
		ASSERT_EQ(Vector2().x, 0);
		ASSERT_EQ(Vector2().y, 0);
		ASSERT_EQ(Vector2(2).x, 2);
		ASSERT_EQ(Vector2(2).y, 2);
		ASSERT_EQ(Vector2(546.31f).x, 546.31f);
		ASSERT_EQ(Vector2(546.31f).y, 546.31f);
		ASSERT_EQ(Vector2(546.31f, 12.4f).x, 546.31f);
		ASSERT_EQ(Vector2(546.31f, 12.4f).y, 12.4f);
		ASSERT_EQ(Vector2(-546.31f, -12.4f).x, -546.31f);
		ASSERT_EQ(Vector2(-546.31f, -12.4f).y, -12.4f);
	}

	TEST_F(Vector2Test, Equality)
	{
		ASSERT_TRUE(EQ(Vector2(), Vector2()));
		ASSERT_TRUE(EQ(Vector2(3), Vector2(3)));

		ASSERT_TRUE(EQ(Vector2::Zero(), Vector2(0.f, 0.f)));
		ASSERT_TRUE(EQ(Vector2::Zero(), Vector2()));
		ASSERT_TRUE(EQ(Vector2::One(), Vector2(1, 1)));
		ASSERT_TRUE(EQ(Vector2::Half(), Vector2(0.5f, 0.5f)));

		ASSERT_TRUE(EQ(Vector2(4, 2), Vector2(4.f, 2.f)));
		ASSERT_TRUE(EQ(Vector2(7.2f, 999.4f), Vector2(7.2f, 999.4f)));
		ASSERT_TRUE(EQ(Vector2(-64.5f, 5.f), Vector2(-64.5f, 5)));
		ASSERT_FALSE(EQ(Vector2(-2.5f, 5.f), Vector2(-2, 5.f)));
		ASSERT_FALSE(EQ(Vector2(-2.f, 3.f), Vector2(2, 3.f)));

		ASSERT_TRUE(EQ(Vector2::Left(), Vector2(0.f, 0.5f)));
		ASSERT_TRUE(EQ(Vector2::Right(), Vector2(1.f, 0.5f)));
		ASSERT_TRUE(EQ(Vector2::Down(), Vector2(0.5f, 1.f)));
		ASSERT_TRUE(EQ(Vector2::Up(), Vector2(0.5f, 0.f)));

		ASSERT_TRUE(EQ(Vector2::TopLeft(), Vector2(0.f, 0.f)));
		ASSERT_TRUE(EQ(Vector2::TopRight(), Vector2(1.f, 0.f)));
		ASSERT_TRUE(EQ(Vector2::BottomLeft(), Vector2(0.f, 1.f)));
		ASSERT_TRUE(EQ(Vector2::BottomRight(), Vector2(1.f, 1.f)));
	}

	TEST_F(Vector2Test, Addition)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2 second = vTestCases1[i];
			Vector2 result = first + second;
			Vector2 result1 = first;
			result1 += second;
			ASSERT_EQ(result.x, first.x + second.x);
			ASSERT_EQ(result.y, first.y + second.y);
			ASSERT_EQ(result.x, result1.x);
			ASSERT_EQ(result.y, result1.y);
			ASSERT_TRUE(EQ(result, Vector2(first.x + second.x, first.y + second.y)));
			ASSERT_TRUE(EQ(result1, Vector2(first.x + second.x, first.y + second.y)));
			ASSERT_TRUE(EQ(result, result1));
		}
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			float second = fTestCases[i];
			Vector2 result = first + second;
			Vector2 result1 = first;
			result1 += second;
			ASSERT_EQ(result.x, first.x + second);
			ASSERT_EQ(result.y, first.y + second);
			ASSERT_EQ(result.x, result1.x);
			ASSERT_EQ(result.y, result1.y);
			ASSERT_TRUE(EQ(result, Vector2(first.x + second, first.y + second)));
			ASSERT_TRUE(EQ(result1, Vector2(first.x + second, first.y + second)));
			ASSERT_TRUE(EQ(result, result1));
		}
	}

	TEST_F(Vector2Test, Subtraction)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2 second = vTestCases1[i];
			Vector2 result = first - second;
			Vector2 result1 = first;
			result1 -= second;
			ASSERT_EQ(result.x, first.x - second.x);
			ASSERT_EQ(result.y, first.y - second.y);
			ASSERT_EQ(result.x, result1.x);
			ASSERT_EQ(result.y, result1.y);
			ASSERT_TRUE(EQ(result, Vector2(first.x - second.x, first.y - second.y)));
			ASSERT_TRUE(EQ(result1, Vector2(first.x - second.x, first.y - second.y)));
			ASSERT_TRUE(EQ(result, result1));
		}
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			float second = fTestCases[i];
			Vector2 result = first - second;
			Vector2 result1 = first;
			result1 -= second;
			ASSERT_EQ(result.x, first.x - second);
			ASSERT_EQ(result.y, first.y - second);
			ASSERT_EQ(result.x, result1.x);
			ASSERT_EQ(result.y, result1.y);
			ASSERT_TRUE(EQ(result, Vector2(first.x - second, first.y - second)));
			ASSERT_TRUE(EQ(result1, Vector2(first.x - second, first.y - second)));
			ASSERT_TRUE(EQ(result, result1));
		}
	}

	TEST_F(Vector2Test, Multiplication)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2 second = vTestCases1[i];
			Vector2 result = first * second;
			Vector2 result1 = first;
			result1 *= second;
			ASSERT_EQ(result.x, first.x * second.x);
			ASSERT_EQ(result.y, first.y * second.y);
			ASSERT_EQ(result.x, result1.x);
			ASSERT_EQ(result.y, result1.y);
			ASSERT_TRUE(EQ(result, Vector2(first.x * second.x, first.y * second.y)));
			ASSERT_TRUE(EQ(result1, Vector2(first.x * second.x, first.y * second.y)));
			ASSERT_TRUE(EQ(result, result1));
		}
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			float second = fTestCases[i];
			Vector2 result = first * second;
			Vector2 result1 = first;
			result1 *= second;
			ASSERT_EQ(result.x, first.x * second);
			ASSERT_EQ(result.y, first.y * second);
			ASSERT_EQ(result.x, result1.x);
			ASSERT_EQ(result.y, result1.y);
			ASSERT_TRUE(EQ(result, Vector2(first.x * second, first.y * second)));
			ASSERT_TRUE(EQ(result1, Vector2(first.x * second, first.y * second)));
			ASSERT_TRUE(EQ(result, result1));
		}
	}

	TEST_F(Vector2Test, Division)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2 second = vTestCases1[i];
			Vector2 result = first / second;
			Vector2 result1 = first;
			result1 /= second;
			ASSERT_EQ(result.x, first.x / second.x);
			ASSERT_EQ(result.y, first.y / second.y);
			ASSERT_EQ(result.x, result1.x);
			ASSERT_EQ(result.y, result1.y);
			ASSERT_TRUE(EQ(result, Vector2(first.x / second.x, first.y / second.y)));
			ASSERT_TRUE(EQ(result1, Vector2(first.x / second.x, first.y / second.y)));
			ASSERT_TRUE(EQ(result, result1));
		}
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			float second = fTestCases[i];
			Vector2 result = first / second;
			Vector2 result1 = first;
			result1 /= second;
			ASSERT_EQ(result.x, first.x / second);
			ASSERT_EQ(result.y, first.y / second);
			ASSERT_EQ(result.x, result1.x);
			ASSERT_EQ(result.y, result1.y);
			ASSERT_TRUE(EQ(result, Vector2(first.x / second, first.y / second)));
			ASSERT_TRUE(EQ(result1, Vector2(first.x / second, first.y / second)));
			ASSERT_TRUE(EQ(result, result1));
		}
	}

	TEST_F(Vector2Test, Magnitude)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			float result = first.Magnitude();
			float expected = sqrtf(first.x * first.x + first.y * first.y);
			ASSERT_EQ(result, expected);
		}
	}

	TEST_F(Vector2Test, Dot)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2 second = vTestCases1[i];
			float result = first.Dot(second);
			float expected = first.x * second.x + first.y * second.y;
			ASSERT_EQ(result, expected);
		}
	}

	TEST_F(Vector2Test, Distance)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2 second = vTestCases1[i];
			float result = first.Distance(second);
			float expected = sqrtf(
				(first.x - second.x) * (first.x - second.x) +
				(first.y - second.y) * (first.y - second.y));
			ASSERT_EQ(result, expected);
		}
	}

	TEST_F(Vector2Test, Normalize)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2 result = first;
			result.Normalize();
			Vector2 result1 = first.NormalizedVector();
			float mag = sqrtf(first.x * first.x + first.y * first.y);
			Vector2 expected = Vector2(first.x / mag, first.y / mag);

			ASSERT_TRUE(EQ(result, result1));
			ASSERT_TRUE(EQ(result, expected));
		}
	}

	TEST_F(Vector2Test, Midpoint)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2 second = vTestCases1[i];
			Vector2 result = first.Midpoint(second);
			Vector2 expected = Vector2((first.x + second.x) * 0.5f, (first.y + second.y) * 0.5f);
			ASSERT_TRUE(EQ(result, expected));
		}
	}

	TEST_F(Vector2Test, ProportionalPoint)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2 second = vTestCases1[i];
			float third = fTestCases[i];
			Vector2 result = first.ProportionalPoint(second, third);
			Vector2 expected = Vector2((first.x + second.x) * third, (first.y + second.y) * third);
			ASSERT_TRUE(EQ(result, expected));
		}
	}

	TEST_F(Vector2Test, SDLPoint)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			shared_ptr<SDL_Point> result = first.GetSDLPoint();

			ASSERT_EQ(result->x, (int)(first.x + 0.5f));
			ASSERT_EQ(result->y, (int)(first.y + 0.5f));
		}
	}

	TEST_F(Vector2Test, Vector2iConversion)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			Vector2i result = (Vector2i)first;

			ASSERT_EQ(result.x, (int)(first.x));
			ASSERT_EQ(result.y, (int)(first.y));
		}
	}
	
	TEST_F(Vector2Test, ToString)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2 first = vTestCases[i];
			ASSERT_EQ(first.ToString(), "(" + to_string(first.x) + ", " + to_string(first.y) + ")");
		}
	}

}