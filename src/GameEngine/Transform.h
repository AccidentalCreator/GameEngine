#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm.hpp>
#include "Component.h"


class Transform : public Component
{
public:
	void Awake();

	void SetTransform(glm::vec3 _position, float _rotation, glm::vec3 _scale);
	
	void SetPosition(glm::vec3 _position);
	void SetRotation(float _rotation);
	void SetSize(glm::vec2 _size);
	void SetScale(glm::vec3 _scale);

	glm::vec3 GetPosition() { return position; };
	float GetRotation() { return rotation; };
	glm::vec2 GetSize() { return size; };
	glm::vec3 GetScale() { return scale; };

	glm::mat4 GetModelMatrix();

private:
	glm::vec3 position;
	float rotation;
	glm::vec2 size;
	glm::vec3 scale;

	glm::mat4 positionMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;
	glm::mat4 modelMatrix;

	void CalcModelMatrix();
};

#endif // !TRANSFORM_H
