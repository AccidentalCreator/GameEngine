#include "Material.h"
#include "VertexArray.h"

#include "stb_image.h"

void Material::Awake()
{
	glGenTextures(1, &id);

	if (!id)
	{
		throw std::exception();
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	VAO = std::make_shared<VertexArray>();
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
	dirty = true;
}

void Material::Display()
{
	if (dirty)
	{
		glBindTexture(GL_TEXTURE_2D, id);
		// Load texture
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(imageData);
		dirty = false;
	}

	glBindTexture(GL_TEXTURE_2D, id);
	glBindVertexArray(VAOid);
}