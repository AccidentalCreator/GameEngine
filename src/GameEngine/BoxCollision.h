#pragma once
#ifndef BOXCOLLISION_H
#define BOXCOLLISION_H

#include <memory>

class Entity;

class BoxCollision
{
public:
	bool CheckCollision(std::weak_ptr<Entity> _a, std::weak_ptr<Entity> _b);

private:

};

#endif // !BOXCOLLISION_H


