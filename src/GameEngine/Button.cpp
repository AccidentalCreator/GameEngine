#include "Button.h"
#include "Entity.h"
#include "Transform.h"
#include "MouseHandler.h"

#include <iostream>

void Button::Start()
{
	runOnce = true;
	size.x = GetEntity()->GetComponent<Transform>()->GetSize().x * GetEntity()->GetComponent<Transform>()->GetScale().x;
	size.y = GetEntity()->GetComponent<Transform>()->GetSize().y * GetEntity()->GetComponent<Transform>()->GetScale().y;
	position.x = GetEntity()->GetComponent<Transform>()->GetPosition().x;
	position.y = GetEntity()->GetComponent<Transform>()->GetPosition().y;

	std::cout << size.x << " " << size.y << std::endl;

	mouseInput = GetMouse();
}

bool Button::CheckClicked()
{
	static int i = 0;
	if (mouseInput->GetMouseButtonDown(0))
	{
		if (mouseInput->GetMousePosition().x >= position.x
			&& mouseInput->GetMousePosition().x <= position.x + size.x)
		{
			if (mouseInput->GetMousePosition().y >= position.y
				&& mouseInput->GetMousePosition().y <= position.y + size.y)
			{
				return true;
			}
		}
	}
	return false;
}