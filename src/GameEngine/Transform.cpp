#include "Transform.h"

#include <gtx/transform.hpp>
#include <iostream>

void Transform::Awake()
{
	//rotation = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
}

void Transform::SetTransform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
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
	// Need to make angle changable variable
	modelMatrix = glm::rotate(modelMatrix, glm::radians(180.0f), glm::vec3(0, 1, 0));

	// need to fix scalling
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