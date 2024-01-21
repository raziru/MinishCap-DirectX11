#include "Framework.h"
#include "Fountain.h"

Fountain::Fountain()
{
	file = L"BackGround/FountainSprite.png";
	scale = { 3,3 };
	AddAction();
	curAction = actions[0];
	curAction->Play();


	Vector2 size = { curAction->Size().x * 0.6f , curAction->Size().y * 0.85f };
	bodyCollider = new ColliderRect(size);
	bodyCollider->SetLabel("Fountain");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;
}

Fountain::~Fountain()
{
	delete bodyCollider;

}

void Fountain::Update()
{
	bodyCollider->Update();
	Actor::Update();
}

void Fountain::Render()
{
	Actor::Render();
	bodyCollider->Render();
	bodyCollider->Debug();
}

void Fountain::AddAction()
{
	actions.emplace(0, new Animation(file, 1, 1));
	actions[0]->SetIndex({ 0 }, false);
}
