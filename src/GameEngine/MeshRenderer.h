#pragma once
#ifndef MESHRENDERER_H
#define MESHRENDERER_H



#include "Component.h"

#include <memory>

class VertexArray;
class ShaderProgram;


class MeshRenderer : public Component
{
public:
	void Awake();

private:
	void Display();

	std::shared_ptr<VertexArray> meshData;
	std::shared_ptr<ShaderProgram> shaders;
};

#endif // !MESHRENDERER_H