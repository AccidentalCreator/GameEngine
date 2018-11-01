#include "Camera.h"
#include <gtc\matrix_transform.hpp>

void Camera::Start(glm::vec3 _position, glm::vec3 _target, glm::vec3 _orientation)
{
	position = _position;
	target = _target;
	orientation = _orientation;

	inverseDirection = glm::normalize(position - target);
	//cameraRight = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), inverseDirection));
	//cameraUp = glm::cross(inverseDirection, cameraRight);
}

glm::mat4 Camera::GetViewMatrix()
{
	viewMatrix = glm::lookAt(position, target, orientation);
	return viewMatrix;
}

void Camera::Display()
{

}
