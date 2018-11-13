#include "Material.h"
#include "VertexArray.h"
#include "Resources.h"
#include "Core.h"

#include "stb_image.h"

#include <iostream>

void Material::Start(std::string _imagePath)
{
	resources = GetCore()->GetResources();
	if (resources->CheckMaterialUsed(_imagePath))
	{
		VAO = resources->GetMatVAO(_imagePath);
		id = resources->GetMatId(_imagePath);
	}
	else
	{
		glGenTextures(1, &id);

		if (!id)
		{
			throw std::exception();
		}

		VAO = std::make_shared<VertexArray>();
		LoadTexture(_imagePath);
	}
	VAOid = VAO->GetID();
}

void Material::LoadTexture(std::string _imagePath)
{
	width = 0;
	height = 0;
	channels = 0;

	imageData = stbi_load(_imagePath.c_str(), &width, &height, &channels, 4);
	
	if (!imageData)
	{
		throw std::exception();
	}

	resources->AddMatData(_imagePath, VAO, id);

	dirty = true;
}

void Material::Display()
{
	if (dirty)
	{
		glBindTexture(GL_TEXTURE_2D, id);
		// Load texture
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(imageData);
		dirty = false;
	}

	glBindTexture(GL_TEXTURE_2D, id);
	glBindVertexArray(VAOid);
}