#include "Mesh.h"
#include "Face.h"

namespace GameEngine
{

	struct MeshSpace
	{
		std::vector<Face> faces;
	};

	Mesh::Mesh() : meshSpace(std::make_shared<MeshSpace>())
	{

	}

	Mesh::~Mesh()
	{
	}

	std::vector<Face>& Mesh::GetFaces()
	{
		return meshSpace->faces;
	}

	void Mesh::AddFace(Face & _face)
	{
		meshSpace->faces.push_back(_face);
	}

}

