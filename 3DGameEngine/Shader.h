#pragma once

#include "FileUtils.h"
#include "Math.h"
#include <glew.h>

namespace GameEngine {
	namespace Graphics {

		class Shader {
		private:
			GLuint m_ShaderID;
			const char* m_VertPath;
			const char* m_FragPath;

		public:
			Shader(const char* vertex, const char* fragment);
			~Shader();


			void setUniform1f(const char* name, float value);
			void setUniform1i(const char* name, int value);
			void setUniform2f(const char* name, const Maths::vec2& vector);
			void setUniform3f(const char* name, const Maths::vec3& vector);
			void setUniform4f(const char* name, const Maths::vec4& vector);

			void setUniformMat4(const GLchar* name, const Maths::mat4& matrix);


			void enable()const;
			void disable()const;

		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);

		};


	}

}
