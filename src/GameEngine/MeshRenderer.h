#pragma once
#ifndef MESHRENDERER_H
#define MESHRENDERER_H

#include "Component.h"
#include "Texture.h"

#include <memory>
#include <string>

class VertexArray;
class ShaderProgram;
class Transform;
class Screen;
class Entity;
class Camera;

class MeshRenderer : public Component
{
public:
	void Awake();
	void AddModel(std::string _modelPath, std::string _texturePath, std::string _vertexPath, std::string _fragPath);
	void AddModel(std::string _modelPath, std::string _vertexPath, std::string _fragPath);

	std::shared_ptr<ShaderProgram> GetShaders() { return shaders; }
	std::shared_ptr<VertexArray> GetMeshData() { return meshData; }
	std::shared_ptr<Transform> GetTransform() { return transform; }


private:
	void Display();

	std::shared_ptr<VertexArray> meshData;
	std::shared_ptr<Texture> texture;
	std::shared_ptr<ShaderProgram> shaders;
	std::shared_ptr<Transform> transform;
	std::shared_ptr<Screen> screen;
	std::shared_ptr<Entity> camera;

	bool runOnce;
};

#endif // !MESHRENDERER_H