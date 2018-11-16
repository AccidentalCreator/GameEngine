#pragma once
#ifndef STATICMESHCOLLIDER_H
#define STATICMESHCOLLIDER_H

#include <vector>
#include <memory>
#include <glm.hpp>

#include "Component.h"

class Mesh;
class Face;

struct SizeData
{
	glm::vec3 maxCoord;
	glm::vec3 minCoord;
};

struct PartitioningColumn
{
	glm::vec3 position;
	glm::vec3 size;
	std::vector<Face> faces;

	bool Colliding(glm::vec3 _position, glm::vec3 _size);
};

class StaticMeshCollider : public Component
{
public:
	void Start();
	SizeData GetData();
	bool Colliding(glm::vec3 _position, glm::vec3 _size);

private:
	std::vector<std::shared_ptr<PartitioningColumn> > columns;
	SizeData size;
	float noOfColumns;
	
	void AddFace(Face _face);
	void FindSizeOfModel();

	//------------------------

	int triBoxOverlap(float boxcenter[3], float boxhalfsize[3], float triverts[3][3]);
	int planeBoxOverlap(float normal[3], float vert[3], float maxbox[3]);
};

#endif // !STATICMESHCOLLIDER_H
