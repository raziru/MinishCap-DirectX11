#include "Framework.h"
#include "Octa.h"


Octa::Octa()
{
	bodyCollider = new ColliderRect({ 14,14 });
	bodyCollider->SetLabel("Octa");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;

	aggroRadius = new ColliderCircle(40);
	aggroRadius->SetLabel("OctaAggro");
	aggroRadius->SetParent(this);
	aggroRadius->IsActive() = true;

	MaxHP = 3;
	HP = MaxHP;
	power = 2;
	speed = 30;
	clamp = 3;

	effect = BULLET;
	magic = new EffectManager(BULLET,this->parent, this->globalPosition);
	SoundManager::GetInstance()->AddSound("OctaShoot", "_Sound/MC_Octorok_Spit.wav");

}

Octa::~Octa()
{
	delete bodyCollider;
	delete aggroRadius;
	delete magic;
}

void Octa::Update()
{
	time += Time::Delta();
	if (time >= attackDelay)
	{
		switch (viewDirect)
		{
		case Actor::FORWARD:
			SetAction(ATTACK_FORWARD);
			
			break;
		case Actor::RIGHT:
			SetAction(ATTACK_SIDE);
			rotation.y = 0;
			break;
		case Actor::LEFT:
			SetAction(ATTACK_SIDE);
			rotation.y = XM_PI;
			break;
		case Actor::BACK:
			SetAction(ATTACK_BACK);
			break;
		default:
			break;
		}
		time = 0;
		isAttack = true;
	}

	if (isAttack == false)
	{
		switch (viewDirect)
		{
		case Actor::FORWARD:
			SetAction(IDLE_FORWARD);
			break;
		case Actor::RIGHT:
			SetAction(IDLE_SIDE);
			rotation.y = XM_PI;
			
			break;
		case Actor::LEFT:
			SetAction(IDLE_SIDE);
			rotation.y = 0;
			break;
		case Actor::BACK:
			SetAction(IDLE_BACK);
			break;
		default:
			break;
		}
	}

	Monster::Update();
	magic->Update();
	//magic->SetTranslation() = {};
	//magic->SetRotation(this->rotation.y);
	bodyCollider->Update();
	aggroRadius->Update();
}

void Octa::Render()
{
	magic->Render();
	bodyCollider->Render();
	aggroRadius->Render();
	Monster::Render();
}

void Octa::Attack()
{
	SoundManager::GetInstance()->Play("OctaShoot");

	switch (viewDirect)
	{
	case Actor::FORWARD:
		magic->Attack({0,-1}, this->globalPosition);

		break;
	case Actor::RIGHT:
		magic->Attack({1,0}, this->globalPosition);

		break;
	case Actor::LEFT:
		magic->Attack({-1,0}, this->globalPosition);

		break;
	case Actor::BACK:
		magic->Attack({0,1}, this->globalPosition);

		break;
	default:
		break;
	}
}

void Octa::SetIDLE()
{
	Attack();
	isAttack = false;
	switch (viewDirect)
	{
	case Actor::FORWARD:
		SetAction(IDLE_FORWARD);
		break;
	case Actor::RIGHT:
		SetAction(IDLE_SIDE);
		rotation.y = 0;

		break;
	case Actor::LEFT:
		SetAction(IDLE_SIDE);
		rotation.y = XM_PI;
		break;
	case Actor::BACK:
		SetAction(IDLE_BACK);
		break;
	default:
		break;
	}
}

void Octa::SetEndEvent()
{
	actions[ATTACK_FORWARD]->SetEndEvent(bind(&Octa::SetIDLE,this));
	actions[ATTACK_SIDE]->SetEndEvent(bind(&Octa::SetIDLE, this));
	actions[ATTACK_BACK]->SetEndEvent(bind(&Octa::SetIDLE, this));
}



