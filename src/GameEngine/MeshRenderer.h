#pragma once
#ifndef MESHRENDERER_H
#define MESHRENDERER_H

#include "Component.h"
#include "Texture.h"

#include <memory>
#include <string>

namespace GameEngine
{

	class VertexArray;
	class ShaderProgram;
	class Transform;
	class Screen;
	class Entity;
	class Camera;

	/**
	* Allows a 3D model to be attatched to a entity
	*/

	class MeshRenderer : public Component
	{
	public:
		/// Initialisation
		void Awake();
		/// Creates vertex array object and sets up shader program
		void Start(std::string _modelPath, std::string _vertexPath, std::string _fragPath);
		/// Creates vertex array object and sets up shader program
		void AddModel(std::string _modelPath, std::string _vertexPath, std::string _fragPath);

		/// Retrieves the shaders assigned
		std::shared_ptr<ShaderProgram> GetShaders() { return shaders; }
		/// Retrieves the mesh data
		std::shared_ptr<VertexArray> GetMeshData() { return meshData; }
		/// Returns the transform of the entity attatched
		std::shared_ptr<Transform> GetTransform() { return transform; }


	private:
		/// Passes all relevant information to the shaders
		void Display();

		std::shared_ptr<VertexArray> meshData;
		std::shared_ptr<Texture> texture;
		std::shared_ptr<ShaderProgram> shaders;
		std::shared_ptr<Transform> transform;
		std::shared_ptr<Screen> screen;
		std::shared_ptr<Entity> camera;

		bool runOnce;
	};

}


#endif // !MESHRENDERER_H