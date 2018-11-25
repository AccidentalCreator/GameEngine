#pragma once
#ifndef FACE_H
#define FACE_H

namespace GameEngine
{
	/**
	* Stores the vertex positon and its texture coordinate
	*/
	struct Vertex
	{
		glm::vec3 position;
		glm::vec2 texCoord;
	};

	/**
	* Stores the position of each trianglulated faces vertex
	*/
	class Face
	{
	public:
		Vertex a;
		Vertex b;
		Vertex c;
	};

}


#endif // !FACE_H