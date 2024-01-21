#include "Framework.h"
#include "Laser.h"

Laser::Laser()
{
	file = L"Effect/Laser/Laser1.png";
	file2 = L"Effect/Laser/Laser2.png";
	file3 = L"Effect/Laser/Laser3.png";
	this->scale = { 3,3 };

	bodyCollider->SetLabel("Laser");

	AddAction();
	curAction = actions[0];
	curAction->Play();
	deleteTime = 15.0f;
	bodyCollider->IsActive() = false;

	SetEndEvent();

	SoundManager::GetInstance()->AddSound("Laser", "_Sound/Laser.wav");

}

Laser::~Laser()
{
}

void Laser::AddAction()
{
	actions.emplace(0, new Animation(file, 3, 1));
	actions[0]->SetPart(0, 2, false);

	actions.emplace(1, new Animation(file2, 1, 1));
	actions[1]->SetPart(0, 0, false);

	actions.emplace(2, new Animation(file3, 2, 1));
	actions[2]->SetPart(0, 1, false);

}

void Laser::DisappearEvent()
{
	
}

void Laser::Attack(Vector2 direct, Vector2 translation)
{

	isActive = true;
	bodyCollider->scale = { 1, 1 };
	this->translation = translation;
	this->direct = direct;
	//rotation.z = acos(Vector2::Dot(direct.GetNormal(),this->direct));
	SetAction(0);
}

void Laser::SetEndEvent()
{
	actions[0]->SetEndEvent(bind(&Actor::SetAction, this, 1));
	actions[1]->SetEndEvent(bind(&Laser::Beam, this));
	actions[2]->SetEndEvent(bind(&Laser::Destroy, this));

}

void Laser::Beam()
{
	SoundManager::GetInstance()->Play("Laser");

	SetAction(2);
	bodyCollider->IsActive() = true;
	bodyCollider->scale = { 1, 10 };
	translation += { 0, -120 };
}

void Laser::Destroy()
{
	duration = 14.5f;
	//translation = { 0,0 };
	bodyCollider->IsActive() = false;


}

void Laser::Update()
{
	Weapon::Update();
	duration += Time::Delta();
	if (duration >= deleteTime)
	{
		isActive = false;
		duration = 0.0f;
	}
}
