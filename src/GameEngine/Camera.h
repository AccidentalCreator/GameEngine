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

	void SetPosition(glm::vec3 _position);
	void SetTarget(glm::vec3 _target) { target = _target; }
	void SetOrientation(glm::vec3 _orientation) { orientation = _orientation; }
	void SetRotation(float _angle, glm::vec3 _orientation);

	std::shared_ptr<glm::vec3> GetCameraFront() { return cameraFront; }
	void SetCameraFront(glm::vec3 _cameraFront) { *cameraFront.get() = _cameraFront; }


private:
	void Display();

	glm::mat4 viewMatrix;
	glm::mat4 rotationMatrix;

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 orientation;

	glm::vec3 target;
	glm::vec3 direction;
	glm::vec3 up;
	glm::vec3 cameraRight;
	glm::vec3 cameraUp;
	std::shared_ptr<glm::vec3> cameraFront;
	
	float angle;
	glm::vec3 rotationOrientation;
};

#endif // ! CAMERA_H
