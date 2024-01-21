#include "Framework.h"
#include "Effect.h"


Effect::Effect()
{
	scale = { 3,3 };
	bodyCollider = new ColliderRect({ 10,10 });
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;
}

Effect::~Effect()
{
	delete bodyCollider;
}

void Effect::Update()
{
	Weapon::Update();
	duration += Time::Delta();
	if (duration>=deleteTime)
	{
		DisappearEvent();
	}


}

