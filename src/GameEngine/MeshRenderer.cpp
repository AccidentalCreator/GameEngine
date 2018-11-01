#include "MeshRenderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Screen.h"
#include "Core.h"
#include "Entity.h"

#include <gtc\matrix_transform.hpp>
#include <iostream>

void MeshRenderer::Awake()
{
	//// Pass data to VBO
	//std::shared_ptr<VertexBuffer> vertexPosistion = std::make_shared<VertexBuffer>(); // Creates VBO
	//// Adds vertex data to buffer

	//// Bottom
	//vertexPosistion->Add(glm::vec3(-1.0f, -1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, -1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, -1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, -1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, -1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, -1.0f, 1.0f));

	//// Top
	//vertexPosistion->Add(glm::vec3(-1.0f, 1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, 1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, 1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, 1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, 1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, 1.0f, 1.0f));

	//// Front
	//vertexPosistion->Add(glm::vec3(-1.0f, -1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, -1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, 1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, -1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, 1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, 1.0f, 1.0f));

	//// Back
	//vertexPosistion->Add(glm::vec3(-1.0f, -1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, 1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, -1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, -1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, 1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, 1.0f, -1.0f));

	//// Left
	//vertexPosistion->Add(glm::vec3(-1.0f, -1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, 1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, -1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, -1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, 1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(-1.0f, 1.0f, -1.0f));

	//// Right
	//vertexPosistion->Add(glm::vec3(1.0f, -1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, -1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, 1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, -1.0f, 1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, 1.0f, -1.0f));
	//vertexPosistion->Add(glm::vec3(1.0f, 1.0f, 1.0f));

	//std::shared_ptr<VertexBuffer> vertexColors = std::make_shared<VertexBuffer>();
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));

	//vertexColors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	//vertexColors->Add(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));

	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));

	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
	//vertexColors->Add(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));

	//std::shared_ptr<VertexBuffer> textureCoords = std::make_shared<VertexBuffer>();
	//textureCoords->Add(glm::vec2(0.0f, 0.0f));
	//textureCoords->Add(glm::vec2(1.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 1.0f));
	//textureCoords->Add(glm::vec2(1.0f, 0.0f));
	//textureCoords->Add(glm::vec2(1.0f, 1.0f));
	//textureCoords->Add(glm::vec2(0.0f, 1.0f));

	//textureCoords->Add(glm::vec2(0.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 1.0f));
	//textureCoords->Add(glm::vec2(1.0f, 0.0f));
	//textureCoords->Add(glm::vec2(1.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 1.0f));
	//textureCoords->Add(glm::vec2(1.0f, 1.0f));

	//textureCoords->Add(glm::vec2(1.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 0.0f));
	//textureCoords->Add(glm::vec2(1.0f, 1.0f));
	//textureCoords->Add(glm::vec2(0.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 1.0f));
	//textureCoords->Add(glm::vec2(1.0f, 1.0f));

	//textureCoords->Add(glm::vec2(0.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 1.0f));
	//textureCoords->Add(glm::vec2(1.0f, 0.0f));
	//textureCoords->Add(glm::vec2(1.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 1.0f));
	//textureCoords->Add(glm::vec2(1.0f, 1.0f));

	//textureCoords->Add(glm::vec2(0.0f, 1.0f));
	//textureCoords->Add(glm::vec2(1.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 1.0f));
	//textureCoords->Add(glm::vec2(1.0f, 1.0f));
	//textureCoords->Add(glm::vec2(1.0f, 0.0f));

	//textureCoords->Add(glm::vec2(1.0f, 1.0f));
	//textureCoords->Add(glm::vec2(1.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 0.0f));
	//textureCoords->Add(glm::vec2(1.0f, 1.0f));
	//textureCoords->Add(glm::vec2(0.0f, 0.0f));
	//textureCoords->Add(glm::vec2(0.0f, 1.0f));


	//// Pass data to VAO
	//meshData = std::make_shared<VertexArray>(); // Create VAO
	//meshData->SetBuffer("in_Position", vertexPosistion); // pass position data to shader attribute
	//meshData->SetBuffer("in_Color", vertexColors); // pass color data to shader attribute
	//meshData->SetBuffer("in_TexCoord", textureCoords);

	//// Tells what shaders to use
	//shaders = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");

	//transform = GetEntity()->GetComponent<Transform>();
	//screen = GetCore()->GetScreen();
	
}

void MeshRenderer::AddModel(std::string _modelPath)
{
	// Pass data to VAO
	meshData = std::make_shared<VertexArray>(_modelPath); // Create VAO

	// Tells what shaders to use
	shaders = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");

	transform = GetEntity()->GetComponent<Transform>();
	screen = GetCore()->GetScreen();
}

void MeshRenderer::Display()
{
	shaders->SetUniform("in_Model", transform->GetModelMatrix());
	shaders->SetUniform("in_Projection", screen->GetProjectionMatric());
	
	glm::mat4 camera = glm::lookAt(glm::vec3(0, 6, -6), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	shaders->SetUniform("in_Camera", camera);

	shaders->Draw(*meshData); 
}

