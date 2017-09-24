#pragma once
#include <iostream>

namespace GameEngine {
	namespace Maths {

		struct vec3 {

			float x, y,z;

			//Constructors
			vec3();
			vec3(const float& x, const float& y, const float& c);

			//Functions
			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);


			//operators
			friend vec3 operator + (vec3 left, const vec3& right);
			friend vec3 operator - (vec3 left, const vec3& right);
			friend vec3 operator * (vec3 left, const vec3& right);
			friend vec3 operator / (vec3 left, const vec3& right);


			bool operator == (const vec3& other);
			bool operator != (const vec3& other);


			vec3& operator +=(const vec3& other);
			vec3& operator -=(const vec3& other);
			vec3& operator *=(const vec3& other);
			vec3& operator /=(const vec3& other);


			friend std::ostream& operator << (std::ostream& stream, const vec3& other);



		};

	}
}
#pragma once
