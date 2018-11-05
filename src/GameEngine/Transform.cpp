#include "Transform.h"

#include <gtx/transform.hpp>
#include <iostream>

void Transform::Awake()
{
	position = glm::vec3(0, 0, 0);
	rotation = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
}

void Transform::SetTransform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
{
	position = _position;
	rotation = _rotation;
	scale = _scale;
}


void Transform::CalcModelMatrix()
{
	//positionMatrix = glm::translate(glm::mat4(1.0f), position);

	//rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	//rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	//rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));



	//scaleMatrix = glm::scale(glm::mat4(1.0f), scale);

	//modelMatrix = positionMatrix * rotationMatrix * scaleMatrix;

	modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, glm::radians(180.0f), glm::vec3(0, 1, 0));
	//modelMatrix = glm::scale(modelMatrix, scale);

}

void Transform::SetPosition(glm::vec3 _position) 
{
	position = _position; 
	CalcModelMatrix();
}

void  Transform::SetRotation(glm::vec3 _rotation)
{
	rotation = _rotation; 
	CalcModelMatrix();
}

void  Transform::SetScale(glm::vec3 _scale)
{
	scale = _scale; 
	CalcModelMatrix();
}