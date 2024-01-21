#include "Framework.h"
#include "Weapon.h"


Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

void Weapon::Update()
{

	if (!isActive)
	{
		return;
	}
	Actor::Update();
	bodyCollider->Update();
	if (onCollsion)
	{
		if (OnEvent != nullptr)
		{
			OnEvent();
		}
	}
	else
	{
		if (OffEvent != nullptr)
		{
			OffEvent();
		}
	}
}

void Weapon::Render()
{
	if (!isActive)
	{
		return;
	}
	Actor::Render();
	bodyCollider->Render();
}

