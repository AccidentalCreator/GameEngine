#include "Camera.h"
#include "Entity.h"
#include "Transform.h"
#include <gtc\matrix_transform.hpp>

void Camera::Start()
{
	position = GetEntity()->GetComponent<Transform>()->GetPosition();
	direction = glm::normalize(position - target);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	cameraRight = glm::normalize(glm::cross(up, direction));
	cameraUp = glm::cross(direction, cameraRight);
	cameraFront = std::make_shared<glm::vec3>(0.0f, 0.0f, 1.0f);
}

glm::mat4 Camera::GetViewMatrix()
{
	position = GetEntity()->GetComponent<Transform>()->GetPosition();
	viewMatrix = glm::lookAt(position, position + *cameraFront, cameraUp);
	return viewMatrix;
}

void Camera::SetPosition(glm::vec3 _position)
{
	position = _position;
	GetEntity()->GetComponent<Transform>()->SetPosition(-position);
}

void Camera::Display()
{

}
