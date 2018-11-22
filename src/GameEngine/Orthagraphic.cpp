#include "Orthagraphic.h"
#include "Core.h"
#include "Screen.h"
#include "ShaderProgram.h"
#include "Entity.h"
#include "Camera.h"
#include "VertexArray.h"
#include "Transform.h"
#include "Texture.h"

#include <gtc\matrix_transform.hpp>

void Orthagraphic::Awake()
{
	runOnce = true;
	glm::vec2 screenSize = GetCore()->GetScreen()->GetSize();
	orthoMatrix = glm::ortho(0.0f, screenSize.x, screenSize.y, 0.0f);
	shaders = GetShaders();
}

void Orthagraphic::Start(std::string _modelPath, std::string _vertexPath, std::string _fragPath)
{
	AddModel(_modelPath, _vertexPath, _fragPath);
}

void Orthagraphic::Display()
{
	if (runOnce)
	{
		texture = GetEntity()->GetComponent<Texture>();
		runOnce = false;
	}

	glDisable(GL_DEPTH_TEST);
	shaders->SetUniform("in_Model", GetEntity()->GetComponent<Transform>()->GetModelMatrix());
	shaders->SetUniform("in_Projection", orthoMatrix);
	shaders->SetUniform("in_Texture", GetEntity()->GetComponent<Texture>());
	shaders->Draw(*GetMeshData());
}