#pragma once
#ifndef MESHRENDERER_H
#define MESHRENDERER_H



#include "Component.h"

#include <memory>

class VertexArray;
class ShaderProgram;
class Transform;
class Screen;
class Entity;


class MeshRenderer : public Component
{
public:
	void Awake();

private:
	void Display();

	std::shared_ptr<VertexArray> meshData;
	std::shared_ptr<ShaderProgram> shaders;
	std::shared_ptr<Transform> transform;
	std::shared_ptr<Screen> screen;

};

#endif // !MESHRENDERER_H