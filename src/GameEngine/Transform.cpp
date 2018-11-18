#include "Transform.h"

#include <gtx/transform.hpp>
#include <iostream>

void Transform::Awake()
{
}

void Transform::SetTransform(glm::vec3 _position, float _rotation, glm::vec3 _scale)
{
	position = _position;
	rotation = _rotation;
	scale = _scale;
	//CalcModelMatrix();
}


void Transform::CalcModelMatrix()
{
	//modelMatrix = glm::mat4(1.0f);
	//modelMatrix = glm::translate(modelMatrix, position);
	//modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation), glm::vec3(0, 1, 0));
	//modelMatrix = glm::scale(modelMatrix, scale);
}

glm::mat4 Transform::GetModelMatrix() 
{
	//CalcModelMatrix();
	glm::mat4 modelMatrix;
	modelMatrix = glm::mat4(1.0f);
	modelMatrix = modelMatrix * glm::translate(position);
	modelMatrix = modelMatrix * glm::rotate(glm::radians(rotation), glm::vec3(0, 1, 0));
	modelMatrix = modelMatrix * glm::scale(scale);
	return modelMatrix; 
};

void Transform::SetPosition(glm::vec3 _position)
{
	position = _position; 
}

void  Transform::SetRotation(float _rotation)
{
	rotation = _rotation; 
}

void  Transform::SetSize(glm::vec3 _size)
{
	renderSize = _size;
}

void  Transform::SetScale(glm::vec3 _scale)
{
	scale = _scale; 
}