#include "mat4.h"


namespace GameEngine { namespace Maths {

	mat4::mat4()
	{
		for (int i = 0; i < 4 * 4; i++)
			elements[i] = 0;
	}

	mat4::mat4(float diagnol)
	{
		for (int i = 0; i < 4 * 4; i++)
			elements[i] = 0;

		elements[0 + 0 * 4] = diagnol;
		elements[1 + 1 * 4] = diagnol;
		elements[2 + 2 * 4] = diagnol;
		elements[3 + 3 * 4] = diagnol;

	}

	mat4 mat4::identity()
	{
		return mat4(1.0f);
	}


	mat4& mat4::multiply(const mat4& other)
	{
		float data[16];
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				float sum = 0.0f;
				for (int k = 0; k < 4; k++)
				{
					sum += elements[j + k * 4] * other.elements[k + i * 4];
				}
				data[j + i * 4] = sum;
			}
		}

		memcpy(elements, data, 4 * 4 * sizeof(float));

		return *this;
	}

	mat4 operator * (mat4 left, const mat4& right)
	{
		
		return left.multiply(right);
	}

	mat4& mat4::operator*=(const mat4& other)
	{
		return multiply(other);
	}

	mat4 mat4:: orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		mat4 result(1.0f);

		result.elements[0 + 0 * 4] = (2 / right - left);
		result.elements[1 + 1 * 4] = (2 / top - bottom);
		result.elements[2 + 2 * 4] = (-2 / far - near);

		result.elements[0 + 3 * 4] = (left + right) / (left - right);
		result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elements[2 + 0 * 4] = (far + near) / (far - near);

		return result;
	}
	
	mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
	{
		mat4 result(1.0f);

		float a = 1.0f / tan(0.5 * fov);
		float b = a / aspectRatio;
		float c = (near + far) / (near - far);
		float d = (2 * near * far) / (near - far);

		result.elements[0 + 0 * 4] = b;
		result.elements[1 + 1 * 4] = a;
		result.elements[2 + 2 * 4] = c;
		result.elements[3 + 2 * 4] = -1.0f;
		result.elements[2 + 3 * 4] = d;

		return result;
	}

	mat4 mat4:: translation(const vec3& translation)
	{
		mat4 result(1.0f);

		result.elements[0 + 3 * 4] = translation.x;
		result.elements[1 + 3 * 4] = translation.y;
		result.elements[2 + 3 * 4] = translation.z;
	
		return result;

	}
	mat4  mat4::rotation(float angle, const vec3& axis)
	{
		mat4 result(1.0f);

		float r = toRadians(angle);
		float c = cos(r);
		float s = sin(r);

		float omc = 1 - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result.elements[0 + 0 * 4] = x * omc + c;
		result.elements[1 + 0 * 4] = y * x * omc + z * s ;
		result.elements[2 + 0 * 4] = x * z * omc - y * s;

		result.elements[0 + 1 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * omc + c;
		result.elements[2 + 1 * 4] = y * z * omc + x * s;

		result.elements[0 + 2 * 4] = x * z * omc + y * s;
		result.elements[1 + 2 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * omc + c;


		return result;

	}

	mat4  mat4::scale(const vec3& scale)
	{
		mat4 result(1.0f);

		result.elements[0 + 0 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;

		return result;


	}





} }