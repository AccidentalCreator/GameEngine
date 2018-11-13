#include "Camera.h"
#include "Entity.h"
#include "Transform.h"
#include <gtc\matrix_transform.hpp>

void Camera::Start(glm::vec3 _position, glm::vec3 _target, glm::vec3 _orientation)
{
	SetPosition(_position);
	target = _target;
	orientation = _orientation;

	inverseDirection = glm::normalize(position - target);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	cameraRight = glm::normalize(glm::cross(up, inverseDirection));
	cameraUp = glm::cross(inverseDirection, cameraRight);
	cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::mat4 Camera::GetViewMatrix()
{
	viewMatrix = glm::lookAt(position, position + cameraFront, cameraUp);
	//CalcRotation();
	return viewMatrix;
}

void Camera::SetPosition(glm::vec3 _position)
{
	position = _position;
	GetEntity()->GetComponent<Transform>()->SetPosition(-position);
}

void Camera::SetRotation(float _angle, glm::vec3 _orientation)
{
	angle = _angle;
	rotationOrientation = _orientation;
}

void Camera::CalcRotation()
{
	viewMatrix = glm::rotate(viewMatrix, glm::radians(angle), rotationOrientation);
}

void Camera::Display()
{

}
