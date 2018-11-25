#pragma once
#ifndef ORTHAGRAPHIC_H
#define ORTHAGRAPHIC_H

#include <glm.hpp>

#include "MeshRenderer.h"

namespace GameEngine
{

	class Texture;
	/**
	* Allows entites to be displayed from an orthagraphic view point
	*/
	class Orthagraphic : public MeshRenderer
	{
	public:
		/// Initialisiation
		virtual void Awake();
		/// Creates vertex array object and sets up shader program
		void Start(std::string _modelPath, std::string _vertexPath, std::string _fragPath);
	private:
		/// Displays the entity in a orthagraphic viewpoint
		virtual void Display();
		glm::mat4 orthoMatrix;
		std::shared_ptr<ShaderProgram> shaders;
		std::shared_ptr<Texture> texture;
	
		bool runOnce;
	};

}


#endif // !ORTHAGRAPHIC_H
