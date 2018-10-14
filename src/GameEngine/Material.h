#pragma once

#ifndef MATERIAL_H
#define MATERIAL_H

#include <fstream>
#include <GL\glew.h>


#include "Component.h"

class VertexArray;

class Material :public Component
{
public:
	void Awake();
	void LoadTexture(std::string _imagePath);

private:
	void Display();

	unsigned char *imageData;

	std::shared_ptr<VertexArray> VAO;

	GLuint id;
	GLuint VAOid;
	int width;
	int height;
	int channels;
	bool dirty;

};

#endif // !MATERIAL_H
