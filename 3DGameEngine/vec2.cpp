#include "vec2.h"

namespace GameEngine { namespace Maths {
	
	vec2::vec2()
	{
		x = 0;
		y = 0;
	}

	vec2::vec2(const float& a, const float& b)
	{
		x = a;
		y = b;
	}

	vec2& vec2::add(const vec2& other)
	{
		this->x += other.x;
		this->y += other.y;

		return *this;
	}
	vec2& vec2::subtract(const vec2& other)
	{
		this->x -= other.x;
		this->y -= other.y;

		return *this;
	}
	vec2& vec2::multiply(const vec2& other)
	{
		this->x *= other.x;
		this->y *= other.y;

		return *this;
	}
	vec2& vec2::divide(const vec2& other)
	{
		this->x /= other.x;
		this->y /= other.y;

		return *this;
	}

	std::ostream& operator << (std::ostream& stream, const vec2& other)
	{
		stream << "vec2: (" << other.x << ", " << other.y << ")" << std::endl;
		return stream;
	}

	vec2 operator+(vec2 left, const vec2& right)
	{
		return left.add(right);

	}
	vec2 operator-(vec2 left, const vec2& right)
	{
		return left.subtract(right);

	}
	vec2 operator*(vec2 left, const vec2& right)
	{
		return left.multiply(right);

	}
	vec2 operator/(vec2 left, const vec2& right)
	{
		return left.divide(right);
	}

	vec2& vec2::operator +=(const vec2& other)
	{
		return add(other);
	}

	vec2& vec2::operator -=(const vec2& other)
	{
		return subtract(other);
	}

	vec2& vec2::operator *=(const vec2& other)
	{
		return multiply(other);
	}

	vec2& vec2::operator /=(const vec2& other)
	{
		return divide(other);

	}
	

	bool vec2:: operator != (const vec2& other)
	{
		return !(*this == other);
	}

	bool vec2:: operator == (const vec2& other)
	{
		return x == other.x && y == other.y;
	}

	








} }