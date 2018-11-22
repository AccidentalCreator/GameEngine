#pragma once
#ifndef STATICMESHCOLLIDER_H
#define STATICMESHCOLLIDER_H

#include <vector>
#include <memory>
#include <glm.hpp>

#include "Component.h"

namespace GameEngine
{

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
		glm::vec3 CollisionAdjustment(glm::vec3 _position, glm::vec3 _size, bool& _solved, glm::vec3 _lastPosition);
		float GetUncollideY() { return uncollideY; }
		bool GetCollidingY() { return collidingY; }

	private:
		std::vector<std::shared_ptr<PartitioningColumn> > columns;
		SizeData size;
		float noOfColumns;
		float tryStep;
		float maxStep;
		float increment;
		float maxIncrement;
	
		void AddFace(Face _face);
		void FindSizeOfModel();

		float uncollideY;
		bool collidingY;
	};

}


#endif // !STATICMESHCOLLIDER_H
