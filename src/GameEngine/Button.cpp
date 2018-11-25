#include "Button.h"
#include "Entity.h"
#include "Transform.h"
#include "MouseHandler.h"

namespace GameEngine
{

	void Button::Start()
	{
		runOnce = true;
		size.x = GetEntity()->GetComponent<Transform>()->GetSize().x * GetEntity()->GetComponent<Transform>()->GetScale().x;
		size.y = GetEntity()->GetComponent<Transform>()->GetSize().y * GetEntity()->GetComponent<Transform>()->GetScale().y;
		position.x = GetEntity()->GetComponent<Transform>()->GetPosition().x;
		position.y = GetEntity()->GetComponent<Transform>()->GetPosition().y;

		mouseInput = GetMouse();
	}

	bool Button::CheckClicked()
	{
		if (mouseInput->GetMouseButtonDown(0))
		{
			if (mouseInput->GetMousePosition().x >= position.x - (size.x / 2)
				&& mouseInput->GetMousePosition().x <= position.x + (size.x / 2))
			{
				if (mouseInput->GetMousePosition().y >= position.y - (size.y / 2)
					&& mouseInput->GetMousePosition().y <= position.y + (size.y / 2))
				{
					return true;
				}
			}
		}
		return false;
	}

}
