#include "Camera.h"
#include <gtc\matrix_transform.hpp>

void Camera::Awake()
{
	position = glm::vec3(0.0f, 0.0f, 3.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	inverseDirection = glm::normalize(position - target);
	cameraRight = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), inverseDirection));
	cameraUp = glm::cross(inverseDirection, cameraRight);
}

glm::mat4 Camera::GetViewMatrix()
{
	viewMatrix = glm::lookAt(position, target, orientation);
	return viewMatrix;
}