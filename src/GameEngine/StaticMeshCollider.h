#pragma once
#ifndef STATICMESHCOLLIDER_H
#define STATICMESHCOLLIDER_H

#include <vector>
#include <memory>
#include <glm.hpp>

#include "Component.h"


struct PartitioningColumn
{
	glm::vec3 position;
	glm::vec3 size;

};

class StaticMeshCollider : public Component
{
private:
	
public:

};

#endif // !STATICMESHCOLLIDER_H
