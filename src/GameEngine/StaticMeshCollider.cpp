#include "StaticMeshCollider.h"
#include "VertexArray.h"
#include "Entity.h"
#include "MeshRenderer.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

namespace GameEngine
{

	// Influenced by Osen's Static mesh collider class - https://github.com/osen/software-3d-renderer/blob/master/src/qplatform/StaticModelCollider.cpp

	int triBoxOverlap(float _colCentre[3], float _halfColSize[3], float triVerts[3][3]);

	void StaticMeshCollider::Start()
	{
		noOfColumns = 10;
		tryStep = 0.001f;
		maxStep = 1.0f;
		increment = 0.01f;
		maxIncrement = 0.5f;

		std::shared_ptr<MeshRenderer> meshRenderer = GetEntity()->GetComponent<MeshRenderer>();
		std::shared_ptr<VertexArray> meshData = meshRenderer->GetMeshData();
		FindSizeOfModel();

		// Create Partioned Columns
		glm::vec3 meshSize = size.maxCoord - size.minCoord;
		glm::vec3 columnSize = meshSize / noOfColumns;
		columnSize.y = meshSize.y; // Top of column is top of model

		for (size_t y = 0; y < noOfColumns; y++)
		{
			// Set position to middle of columns
			glm::vec3 position = size.minCoord + columnSize / 2.0f;
			position.z += (float)y * columnSize.z;

			for (size_t x = 0; x < noOfColumns; x++)
			{
				std::shared_ptr<PartitioningColumn> column = std::make_shared<PartitioningColumn>();
				column->size = columnSize;
				column->position = position;
				columns.push_back(column);
				position.x += columnSize.x;
			}
		}

		// Add faces to vector of faces
		for (size_t i = 0; i < meshData->faces.size(); i++)
		{
			Face face = meshData->faces.at(i);
			AddFace(face);
		}
	}

	void StaticMeshCollider::FindSizeOfModel()
	{
		std::vector<glm::vec3> positions;
		std::shared_ptr<MeshRenderer> meshRenderer = GetEntity()->GetComponent<MeshRenderer>();
		std::shared_ptr<VertexArray> meshData = meshRenderer->GetMeshData();

		// Place all the vertex position data into the positions vector
		for (size_t i = 0; i < meshData->faces.size(); i++)
		{
			Face face = meshData->faces.at(i);
			positions.push_back(face.a.position);
			positions.push_back(face.b.position);
			positions.push_back(face.c.position);
		}

		// Assign positions of first face
		size.maxCoord = positions.at(0);
		size.minCoord = positions.at(0);

		for (size_t i = 1; i < positions.size(); i++)
		{
			// Check max position
			if (positions.at(i).x > size.maxCoord.x)
				size.maxCoord.x = positions.at(i).x;
			if (positions.at(i).y > size.maxCoord.y)
				size.maxCoord.y = positions.at(i).y;
			if (positions.at(i).z > size.maxCoord.z)
				size.maxCoord.z = positions.at(i).z;

			// Check min positions
			if (positions.at(i).x < size.minCoord.x)
				size.minCoord.x = positions.at(i).x;
			if (positions.at(i).y < size.minCoord.y)
				size.minCoord.y = positions.at(i).y;
			if (positions.at(i).z < size.minCoord.z)
				size.minCoord.z = positions.at(i).z;
		}

		// Not Sure why this
		size.minCoord = size.minCoord - glm::vec3(1, 1, 1);
		size.maxCoord = size.maxCoord + glm::vec3(1, 1, 1);
	}

	bool StaticMeshCollider::Colliding(glm::vec3 _position, glm::vec3 _size)
	{
		glm::vec3 position = _position - size.minCoord;
		size_t x = (size_t)(position.x / columns.at(0)->size.x);
		size_t y = (size_t)(position.z / columns.at(0)->size.z);
		size_t index = y * noOfColumns + x;

		if (index >= columns.size())
		{
			return false;
		}

		if (columns.at(index)->Colliding(_position, _size))
		{
			return true;
		}
	
		return false;
	}

	void StaticMeshCollider::AddFace(Face _face)
	{
		float face[3][3] = { 0 };
		face[0][0] = _face.a.position.x;
		face[0][1] = _face.a.position.y;
		face[0][2] = _face.a.position.z;

		face[1][0] = _face.b.position.x;
		face[1][1] = _face.b.position.y;
		face[1][2] = _face.b.position.z;

		face[2][0] = _face.c.position.x;
		face[2][1] = _face.c.position.y;
		face[2][2] = _face.c.position.z;

		bool faceFound = false;

		for (size_t i = 0; i < columns.size(); i++)
		{
			// Not sure what stands for
			float columnCentre[3] = { 0 };
			columnCentre[0] = columns.at(i)->position.x;
			columnCentre[1] = columns.at(i)->position.y;
			columnCentre[2] = columns.at(i)->position.z;

			// Sub collumns overlap
			glm::vec3 subColumn = columns.at(i)->size;
			subColumn.x += 1;
			subColumn.z += 1;

			float halfColumnSize[3] = { 0 };
			halfColumnSize[0] = subColumn.x / 2.0f;
			halfColumnSize[1] = subColumn.y / 2.0f;
			halfColumnSize[2] = subColumn.z / 2.0f;

			if (triBoxOverlap(columnCentre, halfColumnSize, face))
			{
				columns.at(i)->faces.push_back(_face);
				faceFound = true;
			}
		}

		if (!faceFound)
		{
			throw("Face not Found");
		}
	}

	bool PartitioningColumn::Colliding(glm::vec3 _position, glm::vec3 _size)
	{
		for (int i = 0; i < faces.size(); i++)
		{
			float face[3][3] = { 0 };
			face[0][0] = faces.at(i).a.position.x;
			face[0][1] = faces.at(i).a.position.y;
			face[0][2] = faces.at(i).a.position.z;

			face[1][0] = faces.at(i).b.position.x;
			face[1][1] = faces.at(i).b.position.y;
			face[1][2] = faces.at(i).b.position.z;

			face[2][0] = faces.at(i).c.position.x;
			face[2][1] = faces.at(i).c.position.y;
			face[2][2] = faces.at(i).c.position.z;

			float columnCentre[3] = { 0 };
			columnCentre[0] = _position.x;
			columnCentre[1] = _position.y;
			columnCentre[2] = _position.z;

			float halfColumnSize[3] = { 0 };
			halfColumnSize[0] = _size.x / 2.0f;
			halfColumnSize[1] = _size.y / 2.0f;
			halfColumnSize[2] = _size.z / 2.0f;

			if (triBoxOverlap(columnCentre, halfColumnSize, face))
			{
				return true;
			}
		}

		return false;
	}


	glm::vec3 StaticMeshCollider::CollisionAdjustment(glm::vec3 _position, glm::vec3 _size, bool & _solved, glm::vec3 _lastPosition)
	{
		glm::vec3 solve = _position;
		float amount = tryStep;

		_solved = true;

		if (!Colliding(solve, _size))
		{
			collidingY = false;
			return solve;
		}

		_solved = true;

		// Uncollide in Y
		while (true)
		{
			solve.y += amount;
			if (!Colliding(solve, _size))
			{
				break;
			}
			solve.y -= amount;
			amount += tryStep;

			if (amount > maxStep)
			{
				_solved = false;
				break;
			}
		}

		if (_solved)
		{
			uncollideY = solve.y;
			collidingY = true;
			return solve;
		}

		_solved = true;
		amount = increment;

		solve = _position; // Setting solve back to position Why does it still increase;

		// Uncollide in x/z
		while (true)
		{
			solve.x += amount;

			if (!Colliding(solve, _size))
			{
				break;
			}

			solve.x -= amount;
			solve.x -= amount;

			if (!Colliding(solve, _size))
			{
				break;
			}

			solve.x += amount;
			solve.z += amount;

			if (!Colliding(solve, _size))
			{
				break;
			}

			solve.z -= amount;
			solve.z -= amount;

			if (!Colliding(solve, _size))
			{
				break;
			}

			solve.z += amount;

			amount += increment;

			if (amount > maxIncrement)
			{
				_solved = false;
				break;
			}
		}

		if (_solved)
		{
			return solve;
		}
		_solved = true;
		amount = increment;

		// Uncollide in x+z - Corners
		while (true)
		{
			// Top Left
			solve.x -= amount;
			solve.z += amount;

			if (!Colliding(solve, _size))
			{
				break;
			}

			// Top Right
			solve.x += amount;
			solve.x += amount;

			if (!Colliding(solve, _size))
			{
				break;
			}

			// Bottom Right
			solve.z -= amount;
			solve.z -= amount;

			if (!Colliding(solve, _size))
			{
				break;
			}

			// Bottom Left
			solve.x -= amount;
			solve.x -= amount;

			if (!Colliding(solve, _size))
			{
				break;
			}

			solve.z += amount;
			solve.x += amount;
			amount += increment;

			if (amount > maxIncrement)
			{
				_solved = false;
				break;
			}
		}

		return solve;
	
	}

}
