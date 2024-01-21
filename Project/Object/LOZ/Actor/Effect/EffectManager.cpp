#include "Framework.h"
#include "EffectManager.h"


EffectManager::EffectManager(EffectType effect, Transform* parent, Vector2 translation)
{
	switch (effect)
	{
	case BULLET:
		for (UINT i = 0; i < 30; i++)
		{
			effects.push_back(new Bullet);
		}
		break;
	case FIRE:
		for (UINT i = 0; i < 30; i++)
		{
			effects.push_back(new Fire);
		}
		break;
	case LASER:
		for (UINT i = 0; i < 30; i++)
		{
			effects.push_back(new Laser);
		}
		break;
	default:
		break;
	}
	for (Effect* effect : effects)
	{
		effect->SetParent(parent);
		effect->IsActive() = false;
		effect->translation = translation;
	}
}

EffectManager::~EffectManager()
{
	for (Effect* effect : effects)
	{
		delete effect;
	}
	effects.clear();
}

void EffectManager::Update()
{
	for (Effect* effect : effects)
	{
		if (!effect->IsActive())
		{
			continue;
		}
		effect->Update();
	}
}

void EffectManager::Render()
{

	for (Effect* effect : effects)
	{
		if (!effect->IsActive())
		{
			continue;
		}
		effect->Render();
	}
}

void EffectManager::Initialize(Vector2 translation)
{
	for (Effect* effect : effects)
	{
		effect->translation = translation;
		effect->IsActive() = false;
	}
}

void EffectManager::Attack(Vector2 direct,Vector2 translation)
{
	this->translation = translation;
	if (IsEmpty())
	{
		Initialize(this->translation);
	}
	else
	{
		for (Effect* effect : effects)
		{
			if (effect->IsActive())
			{
				continue;
			}
			effect->Attack(direct, translation);
			return;
		}
	}
	
}


void EffectManager::SetRotation(float rotate)
{
	for (Effect* effect : effects)
	{
		effect->rotation.y = rotate;
	}
}

bool EffectManager::IsEmpty()
{
	for (Effect* effect : effects)
	{
		if (!effect->IsActive())
		{
			return false;
		}
	}
	return true;


}

