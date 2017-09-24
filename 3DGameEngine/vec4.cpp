#include "vec4.h"

#include "vec4.h"

namespace GameEngine {
	namespace Maths {

		

		vec4::vec4(const float& a, const float& b, const float& c, const float& d)
		{
			x = a;
			y = b;
			z = c;
			w = d;
		}

		vec4& vec4::add(const vec4& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;

			return *this;
		}
		vec4& vec4::subtract(const vec4& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;

			return *this;
		}
		vec4& vec4::multiply(const vec4& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;

			return *this;
		}
		vec4& vec4::divide(const vec4& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;

			return *this;
		}

		std::ostream& operator << (std::ostream& stream, const vec4& other)
		{
			stream << "vec4: (" << other.x << ", " << other.y << ", " << other.z << ", "<<other.w<< ")" << std::endl;
			return stream;
		}

		vec4 operator+(vec4 left, const vec4& right)
		{
			return left.add(right);

		}
		vec4 operator-(vec4 left, const vec4& right)
		{
			return left.subtract(right);

		}
		vec4 operator*(vec4 left, const vec4& right)
		{
			return left.multiply(right);

		}
		vec4 operator/(vec4 left, const vec4& right)
		{
			return left.divide(right);
		}

		vec4& vec4::operator +=(const vec4& other)
		{
			return add(other);
		}

		vec4& vec4::operator -=(const vec4& other)
		{
			return subtract(other);
		}

		vec4& vec4::operator *=(const vec4& other)
		{
			return multiply(other);
		}

		vec4& vec4::operator /=(const vec4& other)
		{
			return divide(other);

		}


		bool vec4:: operator != (const vec4& other)
		{
			return !(*this == other);
		}

		bool vec4:: operator == (const vec4& other)
		{
			return x == other.x && y == other.y && other.z && other.w;
		}



	}
}