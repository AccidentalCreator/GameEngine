#include "MeshRenderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Screen.h"
#include "Core.h"
#include "Entity.h"
#include "Camera.h"
#include "Resources.h"


#include <gtc\matrix_transform.hpp>
#include <iostream>

void MeshRenderer::Awake()
{
	runOnce = false;
}

void MeshRenderer::Start(std::string _modelPath, std::string _vertexPath, std::string _fragPath)
{
	std::shared_ptr<Resources> resources = GetCore()->GetResources();

	if (resources->CheckMeshUsed(_modelPath))
	{
		meshData = resources->GetMeshData(_modelPath);
	}
	else
	{
		meshData = std::make_shared<VertexArray>(_modelPath); // Create VAO
		resources->AddMeshData(meshData, _modelPath);
	}

	// Tells what shaders to use
	shaders = std::make_shared<ShaderProgram>(_vertexPath, _fragPath);

	GetEntity()->GetComponent<Transform>()->SetSize(meshData->FindRenderSize());
	//texture = std::make_shared<Texture>("../resources/textures/MissingTexture.png");
}

void MeshRenderer::AddModel(std::string _modelPath, std::string _vertexPath, std::string _fragPath)
{
	Start(_modelPath, _vertexPath, _fragPath);
}

void MeshRenderer::Display()
{
	glEnable(GL_DEPTH_TEST);
	if (!runOnce)
	{
		transform = GetEntity()->GetComponent<Transform>();
		screen = GetCore()->GetScreen();
		camera = GetCore()->FindEntityWithComponent<Camera>();
		texture = GetEntity()->GetComponent<Texture>();
		
		runOnce = true;
	}
	shaders->SetUniform("in_Model", transform->GetModelMatrix());
	shaders->SetUniform("in_Projection", screen->GetProjectionMatrix());
	shaders->SetUniform("in_Camera", camera->GetComponent<Camera>()->GetViewMatrix());
	shaders->SetUniform("in_Texture", texture);

	shaders->Draw(*meshData); 
}

