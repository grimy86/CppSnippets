#include "pch.h"

namespace OPERATOR_OVERLOADING
{
#pragma region OPERATOR_OVERLOADING
	struct Vector2
	{
		float x, y;

		Vector2(float x, float y)
			: x(x), y(y) { }

		Vector2 operator+(const Vector2& other) const
		{
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator*(const Vector2& other) const
		{
			return Mul(other);
		}

		Vector2 Add(const Vector2& other) const
		{
			return operator+(other);
		}

		Vector2 Mul(const Vector2& other) const
		{
			return Vector2(x * other.x, y * other.y);
		}

		bool operator==(const Vector2& other) const
		{
			return x == other.x && y == other.y;
		}

		bool operator!=(const Vector2& other) const
		{
			return !(*this == other);
		}
	};
	
	std::ostream& operator<<(std::ostream& stream, const Vector2& other)
	{
		stream << other.x << ", " << other.y;
		return stream;
	}

	void Foo()
	{
		Vector2 position(4.0f, 4.0f);
		Vector2 speed(0.5f, 1.5f);
		Vector2 result = position + speed; // Using the operator+

		std::cout << result << std::endl;
	}
#pragma endregion
}