#pragma once

#ifndef MATERIAL_H
#define MATERIAL_H

#include <fstream>
#include <GL\glew.h>
#include <glm.hpp>

#include "Component.h"

class Material :public Component
{
public:
	void Start(std::string _imagePath);

private:

};

#endif // !MATERIAL_H
