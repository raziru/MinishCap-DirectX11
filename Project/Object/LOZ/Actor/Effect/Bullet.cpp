#include "Framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	file = L"Effect/Bullet/bulletSprite.png";

	AddAction();
	curAction = actions[0];
	curAction->Play();

	this->SetOnEvent(bind(&Bullet::DisappearEvent, this));
	deleteTime = 4.0f;
	speed = 300.0f;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	Effect::Update();
	
	this->translation += direct * speed * Time::Delta();
	
}

void Bullet::AddAction()
{
	actions.emplace(0, new Animation(file, 3, 1));
	actions[0]->SetPart(0, 2, true);
}

void Bullet::DisappearEvent()
{
	isActive = false;
	onCollsion = false;
	duration = 0.0f;
}

void Bullet::Attack(Vector2 direct,Vector2 translation)
{
	this->translation = translation;
	this->direct = direct;
	isActive = true;
}
