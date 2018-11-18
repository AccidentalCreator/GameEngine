#include "Orthagraphic.h"
#include "Core.h"
#include "Screen.h"
#include "ShaderProgram.h"
#include "Entity.h"
#include "Camera.h"
#include "VertexArray.h"
#include "Transform.h"

#include <gtc\matrix_transform.hpp>

void Orthagraphic::Awake()
{
	glm::vec2 screenSize = GetCore()->GetScreen()->GetSize();
	orthoMatrix = glm::ortho(0.0f, screenSize.x, screenSize.y, 0.0f);
	shaders = GetShaders();
}

void Orthagraphic::AddOrtho(std::string _modelPath, std::string _vertexPath, std::string _fragPath)
{
	AddModel(_modelPath, _vertexPath, _fragPath);
}

void Orthagraphic::Display()
{
	shaders->SetUniform("in_Model", GetEntity()->GetComponent<Transform>()->GetModelMatrix());
	shaders->SetUniform("in_Projection", orthoMatrix);
	shaders->Draw(*GetMeshData());
}