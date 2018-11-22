#include "Texture.h"
#include "Resources.h"
#include "Core.h"
#include "stb_image.h"

void Texture::Start(std::string _texPath)
{
	std::shared_ptr<Resources> resources = GetCore()->GetResources();

	if (resources->CheckMaterialUsed(_texPath))
	{
		id = resources->GetMatId(_texPath);
	}
	else
	{
		int w = 0;
		int h = 0;
		int channels = 0;

		unsigned char *data = stbi_load(_texPath.c_str(), &w, &h, &channels, 4);

		if (!data)
		{
			throw std::exception();
		}

		size.x = w;
		size.y = h;

		glGenTextures(1, &id);

		if (!id)
		{
			throw std::exception();
		}

		glBindTexture(GL_TEXTURE_2D, id);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		free(data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);

		resources->AddMatData(_texPath, id);
	}

}

glm::vec2 Texture::GetSize()
{
	return size;
}

GLuint Texture::GetId()
{
	return id;
}
