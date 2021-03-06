/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Object.hh"

#include <glm/gtc/matrix_transform.hpp>

using namespace Entropy::Theia;
using namespace std;
using namespace glm;

Object::Object(Program &prog, const string &m, const string &v, const string &p)
	: Drawable(prog, m, v, p), _model()
{}

Object::~Object() = default;

void Object::Translate(const Vertex &val)
{
	_model = translate(_model, val);

	UpdateModel(_model);
}

void Object::Rotate(const Vertex::value_type &angle, const Vertex &dir)
{
	_model = rotate(_model, radians(angle), dir);

	UpdateModel(_model);
}

void Object::Scale(const Vertex &val)
{
	_model = scale(_model, val);

	UpdateModel(_model);
}
