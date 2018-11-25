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

	/// Stores the max and min size of the mesh
	struct SizeData
	{
		glm::vec3 maxCoord;
		glm::vec3 minCoord;
	};

	/// Stores the data for each column
	struct PartitioningColumn
	{
		glm::vec3 position;
		glm::vec3 size;
		std::vector<Face> faces;
		/// Checks if an object is colliding with the faces inside its self
		bool Colliding(glm::vec3 _position, glm::vec3 _size);
	};

	class StaticMeshCollider : public Component
	{
	public:
		/// Initialisation
		void Start();
		/// Calculates which column the object is colliding with
		bool Colliding(glm::vec3 _position, glm::vec3 _size);
		/// Adjusts the object position to prevent it from colliding
		glm::vec3 CollisionAdjustment(glm::vec3 _position, glm::vec3 _size, bool& _solved, glm::vec3 _lastPosition);
		/// Returns the y coordinate of the object if its colliding in with the y of the object
		float GetUncollideY() { return uncollideY; }
		/// Returns true if colliding with the y coordinate of the mesh
		bool GetCollidingY() { return collidingY; }

	private:
		std::vector<std::shared_ptr<PartitioningColumn> > columns;
		SizeData size;
		float noOfColumns;
		float tryStep;
		float maxStep;
		float increment;
		float maxIncrement;
		
		/// Adds a face into the columns
		void AddFace(Face _face);
		/// Calculates the render size of the model
		void FindSizeOfModel();

		float uncollideY;
		bool collidingY;
	};

}


#endif // !STATICMESHCOLLIDER_H
