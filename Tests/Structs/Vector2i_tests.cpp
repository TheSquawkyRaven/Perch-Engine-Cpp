#include "pch.h"

#include "../PerchEngine-Cpp/src/Structs/Vector2i.h"
#include "memory.h"

using namespace std;
using namespace Perch;

namespace Structs
{

	static bool EQ(const Vector2i& lhs, const Vector2i& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	class Vector2iTest : public testing::Test
	{

	protected:

		void SetUp() override
		{

		}

		Vector2i vTestCases[8] = {
			Vector2i(6, 2),
			Vector2i(-5, 3),
			Vector2i(-62, 75),
			Vector2i(54, 64),
			Vector2i(534, 65),
			Vector2i(-43, 434),
			Vector2i(463575, 143565),
			Vector2i(-5413469, -74204222),
		};

	};

	TEST_F(Vector2iTest, Basic)
	{
		ASSERT_EQ(Vector2i().x, 0);
		ASSERT_EQ(Vector2i().y, 0);
		ASSERT_EQ(Vector2i(2).x, 2);
		ASSERT_EQ(Vector2i(2).y, 2);
		ASSERT_EQ(Vector2i(546).x, 546);
		ASSERT_EQ(Vector2i(546).y, 546);
		ASSERT_EQ(Vector2i(546, 12).x, 546);
		ASSERT_EQ(Vector2i(546, 12).y, 12);
		ASSERT_EQ(Vector2i(-546, -12).x, -546);
		ASSERT_EQ(Vector2i(-546, -12).y, -12);
	}

	TEST_F(Vector2iTest, Equality)
	{
		ASSERT_TRUE(EQ(Vector2i(), Vector2i()));

		ASSERT_TRUE(EQ(Vector2i(4, 2), Vector2i(4, 2)));
		ASSERT_TRUE(EQ(Vector2i(7, 999), Vector2i(7, 999)));
		ASSERT_TRUE(EQ(Vector2i(-64, 5), Vector2i(-64, 5)));
		ASSERT_FALSE(EQ(Vector2i(-2, 5), Vector2i(-7, 2)));
		ASSERT_FALSE(EQ(Vector2i(-2, 3), Vector2i(2, -3)));
	}

	TEST_F(Vector2iTest, ToString)
	{
		for (int i = 0; i < 8; i++)
		{
			Vector2i first = vTestCases[i];
			ASSERT_EQ(first.ToString(), "(" + to_string(first.x) + ", " + to_string(first.y) + ")");
		}
	}

}