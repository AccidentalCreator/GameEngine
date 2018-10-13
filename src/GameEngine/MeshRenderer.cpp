#include "MeshRenderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"

#include <iostream>

void MeshRenderer::Awake()
{
	// Pass data to VBO
	std::shared_ptr<VertexBuffer> vertexPosistion = std::make_shared<VertexBuffer>(); // Creates VBO
	// Adds vertex data to buffer
	vertexPosistion->Add(glm::vec3(0.0f, 0.5f, 0.0f));
	vertexPosistion->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
	vertexPosistion->Add(glm::vec3(0.5f, -0.5f, 0.0f));

	std::shared_ptr<VertexBuffer> vertexColors = std::make_shared<VertexBuffer>();
	vertexColors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	vertexColors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	vertexColors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	// Pass data to VAO
	meshData = std::make_shared<VertexArray>(); // Create VAO
	meshData->SetBuffer("in_Position", vertexPosistion); // pass position data to shader attribute
	meshData->SetBuffer("in_Color", vertexColors); // pass color data to shader attribute

	// Tells what shaders to use
	shaders = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");

}

void MeshRenderer::Display()
{
	shaders->SetUniform("in_Model", glm::mat4(1.0f));
	shaders->SetUniform("in_Projection", glm::mat4(1.0f));
	shaders->Draw(*meshData); // Should use smart pointer???
}