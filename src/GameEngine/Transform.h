#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm.hpp>
#include <memory>

#include "Component.h"

namespace GameEngine
{
	/**
	* Handles the objects position, rotation and scale
	*/
	class Transform : public Component
	{
	public:
		/// Initialisatiol
		void Awake();

		/// Sets all components of the transform
		void SetTransform(glm::vec3 _position, float _rotation, glm::vec3 _scale);
		/// Sets the position of the object
		void SetPosition(glm::vec3 _position);
		/// Sets the rotaion of the object
		void SetRotation(float _rotation);
		/// Sets the size of the object
		void SetSize(glm::vec3 _size);
		/// Sets the scale of the object
		void SetScale(glm::vec3 _scale);
		/// Returns the position of the object
		glm::vec3 GetPosition() { return position; };
		/// Returns the rotation of the object
		float GetRotation() { return rotation; };
		/// Returns the size of the object
		glm::vec3 GetSize() { return renderSize; };
		/// Returns the scale of the object
		glm::vec3 GetScale() { return scale; };
		/// Gets the size of the object in game (Model size * scale)
		glm::vec3 GetInWorldSize();
		/// Returns the models matrix
		glm::mat4 GetModelMatrix();

	private:
		glm::vec3 position;
		float rotation;
		glm::vec3 renderSize;
		glm::vec3 scale;

		glm::mat4 positionMatrix;
		glm::mat4 rotationMatrix;
		glm::mat4 scaleMatrix;

	};

}



#endif // !TRANSFORM_H
