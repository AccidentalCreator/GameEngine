#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm.hpp>
#include <memory>
#include "Component.h"

namespace GameEngine
{

	class Transform : public Component
	{
	public:
		void Awake();

		void SetTransform(glm::vec3 _position, float _rotation, glm::vec3 _scale);
	
		void SetPosition(glm::vec3 _position);
		void SetRotation(float _rotation);
		void SetSize(glm::vec3 _size);
		void SetScale(glm::vec3 _scale);

		glm::vec3 GetPosition() { return position; };
		float GetRotation() { return rotation; };
		glm::vec3 GetSize() { return renderSize; };
		glm::vec3 GetScale() { return scale; };
		glm::vec3 GetInWorldSize();

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
