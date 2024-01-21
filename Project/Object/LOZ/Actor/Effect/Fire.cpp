#include "Framework.h"
#include "Fire.h"

Fire::Fire()
{
	file = L"Effect/Fire/Movingfire.png";
	file2 = L"Effect/Fire/Fire.png";

	bodyCollider->SetLabel("Fire");

	AddAction();

	curAction = actions[0];
	curAction->Play();
	this->SetOnEvent(bind(&Fire::CollisionLink, this));

	deleteTime = 6.0f;
	speed = 80.0f;
	SoundManager::GetInstance()->AddSound("FireShoot", "_Sound/OOT_Anubis_Fire_Shoot.wav");
	SoundManager::GetInstance()->AddSound("FireBurn", "_Sound/OOT_Anubis_Fire_Burn.wav");

}

Fire::~Fire()
{
}

void Fire::AddAction()
{
	actions.emplace(0, new Animation(file, 4, 1));
	actions[0]->SetPart(0, 3, true);
	actions.emplace(1, new Animation(file2, 6, 1,0,0.2));
	actions[1]->SetPart(0, 4, true);
	

	
		
}

void Fire::Update()
{
	Effect::Update();
	if (canMove)
	{
		this->translation += direct * speed * Time::Delta();
	}
}

void Fire::DisappearEvent()
{
	//isActive = false;
	/*onCollsion = false;
	duration = 0.0f;*/

	//canMove = false;
	//SetAction(1);
	////duration = 0.0f;
	//onCollsion = false;
	////isActive = false;
	isActive = false;

	SoundManager::GetInstance()->Stop("FireShoot");
	SoundManager::GetInstance()->Stop("FireBurn");

}

void Fire::CollisionLink()
{
	SoundManager::GetInstance()->Play("FireBurn");
	canMove = false;
	SetAction(1);
	onCollsion = false;
}

void Fire::Attack(Vector2 direct, Vector2 translation)
{
	//onCollsion = false;
	SoundManager::GetInstance()->Play("FireShoot");

	duration = 0.0f;
	canMove = true;
	speed = 200.0f;
	SetAction(0);
	this->translation = translation;
	this->direct = direct;
	isActive = true;
}

void Fire::SetEndEvent()
{
	actions[1]->SetEndEvent(bind(&Fire::Destory, this));
}

void Fire::Destory()
{
	isActive = false;

}

