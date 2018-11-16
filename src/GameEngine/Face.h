#pragma once
#ifndef FACE_H
#define FACE_H

struct Vertex
{
	glm::vec3 position;
	glm::vec2 texCoord;
};

class Face
{
public:
	Vertex a;
	Vertex b;
	Vertex c;
};

#endif // !FACE_H