#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>
#include <memory>
#include "Component.h"

class Camera : public Component
{
public:
	void Start();
	glm::mat4 GetViewMatrix();

	std::shared_ptr<glm::vec3> GetCameraFront() { return cameraFront; }
	void SetCameraFront(glm::vec3 _cameraFront) { *cameraFront.get() = _cameraFront; }
	void SetTarget(glm::vec3 _target);

private:
	void Display();

	glm::mat4 viewMatrix;

	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 direction;
	glm::vec3 up;
	glm::vec3 cameraRight;
	glm::vec3 cameraUp;
	std::shared_ptr<glm::vec3> cameraFront;
};

#endif // ! CAMERA_H
