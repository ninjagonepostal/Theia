/*	Copyright 2016 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_THEIA_SHADER_INC
#	define ENTROPY_THEIA_SHADER_INC

#	include "Exception.hh"
#	include <memory>

	namespace Entropy
	{
		namespace Theia
		{
			ENTROPY_ERROR_INFO(ShaderLog, std::string);

			class Shader
			{
				public:
					class Type
					{
						public:
							explicit Type(const GLenum &);
							const GLenum &Value() const;
							bool operator == (const Type &) const;
							bool operator != (const Type &) const;
						private:
							GLenum _val;
					};
					static const Type Vertex;
					static const Type Fragment;
					static const Type Geometry;
					static const Type Compute;
				public:
					Shader(const Type &, const std::string &);
					Shader(const Shader &) = delete;
					~Shader();
					const GLuint &Handle() const;
				private:
					GLuint _shader;
			};
		}
	}

#endif
