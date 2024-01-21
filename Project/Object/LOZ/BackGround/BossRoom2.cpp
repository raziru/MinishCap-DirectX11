#include "Framework.h"
#include "BossRoom2.h"


BossRoom2::BossRoom2()
{
	file = L"BackGround/BossRoom2.png";
	scale = { 3,3 };
	AddAction();
	curAction = actions[0];
	curAction->Play();

	Vector2 size = { curAction->Size().x * 0.9f , curAction->Size().y * 0.9f };
	bodyCollider = new ColliderRect(size);
	bodyCollider->SetLabel("BossRoom2");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;
}

BossRoom2::~BossRoom2()
{
	delete bodyCollider;

}

void BossRoom2::Update()
{
	bodyCollider->Update();
	Actor::Update();
}

void BossRoom2::Render()
{
	Actor::Render();
	bodyCollider->Render();
}

void BossRoom2::AddAction()
{
	actions.emplace(0, new Animation(file, 1, 1));
	actions[0]->SetIndex({ 0 }, false);
}
