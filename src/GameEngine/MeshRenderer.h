#pragma once
#ifndef MESHRENDERER_H
#define MESHRENDERER_H



#include "Component.h"

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
	void AddModel(std::string _modelPath);


private:
	void Display();

	std::shared_ptr<VertexArray> meshData;
	std::shared_ptr<ShaderProgram> shaders;
	std::shared_ptr<Transform> transform;
	std::shared_ptr<Screen> screen;
	std::shared_ptr<Camera> camera;

};

#endif // !MESHRENDERER_H