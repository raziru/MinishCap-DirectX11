#include "Framework.h"
#include "BossRoom3.h"

BossRoom3::BossRoom3()
{
	file = L"BackGround/BossRoom3.png";
	scale = { 3,3 };
	AddAction();
	curAction = actions[0];
	curAction->Play();

	Vector2 size = { curAction->Size().x * 0.9f , curAction->Size().y * 0.9f };
	bodyCollider = new ColliderRect(size);
	bodyCollider->SetLabel("BossRoom3");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;
}

BossRoom3::~BossRoom3()
{
	delete bodyCollider;

}

void BossRoom3::Update()
{
	bodyCollider->Update();
	Actor::Update();
}

void BossRoom3::Render()
{
	Actor::Render();
	bodyCollider->Render();
}

void BossRoom3::AddAction()
{
	actions.emplace(0, new Animation(file, 1, 1));
	actions[0]->SetIndex({ 0 }, false);
}
