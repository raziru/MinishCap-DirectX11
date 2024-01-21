#include "Framework.h"
#include "Cythal.h"


Cythal::Cythal()
{
	file = L"BackGround/Cythal5.png";
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

Cythal::~Cythal()
{
	delete bodyCollider;

}

void Cythal::Update()
{
	bodyCollider->Update();
	Actor::Update();
}

void Cythal::Render()
{
	Actor::Render();
	bodyCollider->Render();
	bodyCollider->Debug();
}

void Cythal::AddAction()
{
	actions.emplace(0, new Animation(file, 1, 1));
	actions[0]->SetIndex({ 0 }, false);
}
