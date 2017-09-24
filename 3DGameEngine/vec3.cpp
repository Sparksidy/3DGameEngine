#include "vec3.h"

namespace GameEngine { namespace Maths {

	vec3::vec3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	vec3::vec3(const float& a, const float& b, const float& c)
	{
		x = a;
		y = b;
		z = c;
	}

	vec3& vec3::add(const vec3& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;

		return *this;
	}
	vec3& vec3::subtract(const vec3& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;

		return *this;
	}
	vec3& vec3::multiply(const vec3& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;

		return *this;
	}
	vec3& vec3::divide(const vec3& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;

		return *this;
	}

	std::ostream& operator << (std::ostream& stream, const vec3& other)
	{
		stream << "vec3: (" << other.x << ", " << other.y << ", " << other.z << ")"<< std::endl;
		return stream;
	}

	vec3 operator+(vec3 left, const vec3& right)
	{
		return left.add(right);

	}
	vec3 operator-(vec3 left, const vec3& right)
	{
		return left.subtract(right);

	}
	vec3 operator*(vec3 left, const vec3& right)
	{
		return left.multiply(right);

	}
	vec3 operator/(vec3 left, const vec3& right)
	{
		return left.divide(right);
	}

	vec3& vec3::operator +=(const vec3& other)
	{
		return add(other);
	}

	vec3& vec3::operator -=(const vec3& other)
	{
		return subtract(other);
	}

	vec3& vec3::operator *=(const vec3& other)
	{
		return multiply(other);
	}

	vec3& vec3::operator /=(const vec3& other)
	{
		return divide(other);

	}


	bool vec3:: operator != (const vec3& other)
	{
		return !(*this == other);
	}

	bool vec3:: operator == (const vec3& other)
	{
		return x == other.x && y == other.y && other.z;
	}



} }