#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>
#include <memory>
#include "Component.h"

namespace GameEngine
{
	/**
	* Turns an entity into an camera viewpoint
	*/
	class Camera : public Component
	{
	public:
		void Start();
		/// Returns the view matrix
		glm::mat4 GetViewMatrix();

		/// Returns the direction the camera is facing
		std::shared_ptr<glm::vec3> GetCameraFront() { return cameraFront; }
		/// Sets the direction the camera is facing
		void SetCameraFront(glm::vec3 _cameraFront) { *cameraFront.get() = _cameraFront; }
		/// Sets the target for the camera to look at
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

}


#endif // ! CAMERA_H
