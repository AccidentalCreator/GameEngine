#pragma once
#ifndef MESH_H
#define MESH_H

#include <memory>
#include <vector>
#include <glm.hpp>

namespace GameEngine
{

	struct MeshSpace;
	struct Face;
	/**
	*	Stores a a vector of a mesh's faces
	*/
	class Mesh
	{
	public:
		/// Mesh constructor
		Mesh();
		/// Mesh deconstructor
		~Mesh();
		/// Returns a vector of all the faces in the mesh
		std::vector<Face>& GetFaces();
		/// Adds a face to the vector of faces
		void AddFace(Face& _face);

	private:
		std::shared_ptr<MeshSpace> meshSpace;
	};

}


#endif // !MESH_H
