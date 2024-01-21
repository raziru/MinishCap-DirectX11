#include "Framework.h"
#include "TheEnd.h"

TheEnd::TheEnd()
{
	file = L"BackGround/TheEnd.png";
	//scale = { 3,3 };
	AddAction();
	curAction = actions[0];
	curAction->Play();

	Vector2 size = { curAction->Size().x * 0.9f , curAction->Size().y * 0.9f };
	bodyCollider = new ColliderRect(size);
	bodyCollider->SetLabel("TheEnd");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;
}

TheEnd::~TheEnd()
{
	delete bodyCollider;

}

void TheEnd::Update()
{
	bodyCollider->Update();
	Actor::Update();
}

void TheEnd::Render()
{
	Actor::Render();
	bodyCollider->Render();
}

void TheEnd::AddAction()
{
	actions.emplace(0, new Animation(file, 1, 1));
	actions[0]->SetIndex({ 0 }, false);
}
