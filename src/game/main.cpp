#include <GameEngine\GameEngine.h>
// Include game engine

#include <iostream>
#include <memory>

class Player : public Component
{
public:
	void OnTick()
	{
		//std::cout << "Hello World" << std::endl;
	}
};

int main()
{

	std::shared_ptr<Core> core = Core::Initialize();

	std::shared_ptr<Entity> camera = core->AddEntity();
	std::shared_ptr<Camera> cam = camera->AddComponent<Camera>(glm::vec3(0, 5, -10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	float catSpeed = 0.5f;

	std::shared_ptr<Entity> cat = core->AddEntity();
	std::shared_ptr<MeshRenderer> catRenderer = cat->AddComponent<MeshRenderer>();
	catRenderer->AddModel("../resources/models/cat.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	std::shared_ptr<Material> material = cat->AddComponent<Material>("../resources/textures/cat.png");
	cat->GetComponent<Transform>()->SetTransform(glm::vec3(2, 0, 0), 180.0f, glm::vec3(1, 1, 1));

	std::shared_ptr<Entity> cat2 = core->AddEntity();
	std::shared_ptr<MeshRenderer> cat2Renderer = cat2->AddComponent<MeshRenderer>();
	cat2Renderer->AddModel("../resources/models/cat.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	//std::shared_ptr<Material> material2 = cat2->AddComponent<Material>("../resources/textures/cat.png");
	cat2->GetComponent<Transform>()->SetTransform(glm::vec3(-1, 0, 0), 180.0f, glm::vec3(1, 1, 1));

	//std::shared_ptr<Entity> cube = core->AddEntity();
	//std::shared_ptr<MeshRenderer> meshRenderer = cube->AddComponent<MeshRenderer>();
	//std::shared_ptr<Material> material = cube->AddComponent<Material>();
	//material->LoadTexture("../resources/textures/wall.jpg");

	std::shared_ptr<Entity> cat3 = core->AddEntity();
	std::shared_ptr<Orthagraphic> cat3Renderer = cat3->AddComponent<Orthagraphic>();
	cat3Renderer->AddModel("../resources/models/cube.obj", "../resources/shaders/Ortho.vert", "../resources/shaders/Ortho.frag");
	//std::shared_ptr<Material> material3 = cat3->AddComponent<Material>("../resources/textures/cat.png");
	cat3->GetComponent<Transform>()->SetTransform(glm::vec3(580, 70, 0), 0.0f, glm::vec3(50, 50, 1));

	std::shared_ptr<Sound> sound = std::make_shared<Sound>("../resources/sounds/dixie_horn.ogg");
	sound->Play();

	core->Start();


	return 0;
}
