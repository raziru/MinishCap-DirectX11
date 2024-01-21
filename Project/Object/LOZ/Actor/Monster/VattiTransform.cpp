#include "Framework.h"
#include "VattiTransform.h"

VattiTransform::VattiTransform()
{
	file = L"Monster/VattiTransform.png";
	AddAction();

	curAction = actions[0];
	curAction->Play();

	bodyCollider = new ColliderRect(curAction->Size());
	bodyCollider->SetLabel("VattiTransformCollider");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;

	aggroRadius = new ColliderCircle(80);
	aggroRadius->SetLabel("VattiTransformaggro");
	aggroRadius->SetParent(this);
	aggroRadius->IsActive() = true;

	MaxHP = 3;
	HP = MaxHP;
	power = 2;
	speed = 30;
	clamp = 3;
	magic = new EffectManager(LASER, this->parent, this->globalPosition);
}

VattiTransform::~VattiTransform()
{
	delete magic;
}

void VattiTransform::Update()
{
	time += Time::Delta();
	if (time >= attackDelay)
	{
		for (UINT i = 0; i < 3; i++)
		{
			Attack();

		}
		time = 0;
	}


	aggroRadius->Update();
	bodyCollider->Update();
	magic->Update();
	Monster::Update();
}

void VattiTransform::Render()
{
	aggroRadius->Render();
	bodyCollider->Render();
	Monster::Render();
	magic->Render();
}

void VattiTransform::Attack()
{
	switch (viewDirect)
	{
	case Actor::FORWARD:
		magic->Attack({ 0,-1 }, this->globalPosition+Vector2(Math::Random(-150,150), Math::Random(-150,150)));

		break;
	case Actor::RIGHT:
		magic->Attack({ -1,0 }, this->globalPosition + Vector2(Math::Random(-150, 150), Math::Random(-150, 150)));

		break;
	case Actor::LEFT:
		magic->Attack({ 1,0 }, this->globalPosition + Vector2(Math::Random(-150, 150), Math::Random(-150, 150)));

		break;
	case Actor::BACK:
		magic->Attack({ 0,1 }, this->globalPosition + Vector2(Math::Random(-150, 150), Math::Random(-150, 150)));

		break;
	default:
		break;
	}
}

void VattiTransform::AddAction()
{
	actions.emplace(0, new Animation(file, 5, 2));
	actions[0]->SetAll();
}
