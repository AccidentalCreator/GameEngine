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
	CalcModelMatrix();
}


void Transform::CalcModelMatrix()
{
	modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation), glm::vec3(0, 1, 0));
	modelMatrix = glm::scale(modelMatrix, scale);
}

glm::mat4 Transform::GetModelMatrix() 
{
	CalcModelMatrix();
	return modelMatrix; 
};

void Transform::SetPosition(glm::vec3 _position) 
{
	position = _position; 
	CalcModelMatrix();
}

void  Transform::SetRotation(float _rotation)
{
	rotation = _rotation; 
	CalcModelMatrix();
}

void  Transform::SetSize(glm::vec2 _size)
{
	size = _size;
	CalcModelMatrix();
}

void  Transform::SetScale(glm::vec3 _scale)
{
	scale = _scale; 
	CalcModelMatrix();
}