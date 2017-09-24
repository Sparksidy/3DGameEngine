#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace GameEngine {
	namespace Maths {

		inline float toRadians(float degrees)
		{
			return degrees * M_1_PI / 180.0f;
		}


	}
}


