#pragma once

#ifndef TRIANGLERENDERER_H
#define TRIANGLERENDERER_H

#include <GL\glew.h>

class TriangleRenderer
{
public:
	~TriangleRenderer();
	void OnInit();

private:
	void OnDisplay();
	GLuint programId;
	GLuint VBOId;
	GLuint VAOId;

	const GLfloat positions[] = {
		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};
};

#endif // !TRIANGLERENDERER_H
