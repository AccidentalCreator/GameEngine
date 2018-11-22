#pragma once
#ifndef ORTHAGRAPHIC_H
#define ORTHAGRAPHIC_H

#include <glm.hpp>

#include "MeshRenderer.h"

class Texture;

class Orthagraphic : public MeshRenderer
{
public:
	virtual void Awake();
	void Start(std::string _modelPath, std::string _vertexPath, std::string _fragPath);
private:
	virtual void Display();
	glm::mat4 orthoMatrix;
	std::shared_ptr<ShaderProgram> shaders;
	std::shared_ptr<Texture> texture;
	
	bool runOnce;
};

#endif // !ORTHAGRAPHIC_H
