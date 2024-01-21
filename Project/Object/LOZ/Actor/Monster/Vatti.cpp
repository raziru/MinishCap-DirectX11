#include "Framework.h"
#include "Vatti.h"



Vatti::Vatti()
{
	file = L"Monster/VattiNormal.png";

	AddAction();

	curAction = actions[IDLE_FORWARD];
	curAction->Play();

	bodyCollider = new ColliderRect(curAction->Size());
	bodyCollider->SetLabel("VattiCollider");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;

	aggroRadius = new ColliderCircle(70);
	aggroRadius->SetLabel("Vattiaggro");
	aggroRadius->SetParent(this);
	aggroRadius->IsActive() = true;

	MaxHP = 3;
	HP = MaxHP;
	power = 2;
	speed = 30;
	clamp = 3;
	magic = new EffectManager(FIRE, this->parent, this->globalPosition);
	SetEndEvent();
}

Vatti::~Vatti()
{
	delete bodyCollider;
	delete aggroRadius;
	delete magic;
}

void Vatti::Update()
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
			SetAction(WALK_FORWARD);
			break;
		case Actor::RIGHT:
			SetAction(WALK_SIDE);
			rotation.y = 0;

			break;
		case Actor::LEFT:
			SetAction(WALK_SIDE);
			rotation.y = XM_PI;

			break;
		case Actor::BACK:
			SetAction(WALK_BACK);

			break;
		default:
			break;
		}
	}
	aggroRadius->Update();
	bodyCollider->Update();
	magic->Update();
	Monster::Update();
}

void Vatti::Render()
{
	aggroRadius->Render();
	bodyCollider->Render();
	magic->Render();
	Monster::Render();
}

void Vatti::Attack()
{
	switch (viewDirect)
	{
	case Actor::FORWARD:
		magic->Attack({ 0,-1 },this->globalPosition);

		break;
	case Actor::RIGHT:
		magic->Attack({ -1,0 }, this->globalPosition);

		break;
	case Actor::LEFT:
		magic->Attack({ 1,0 }, this->globalPosition);

		break;
	case Actor::BACK:
		magic->Attack({ 0,1 }, this->globalPosition);

		break;
	default:
		break;
	}
}

void Vatti::SetIDLE()
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


void Vatti::AddAction()
{
	actions.emplace(IDLE_FORWARD, new Animation(file, 11, 7));
	actions.emplace(IDLE_SIDE,    new Animation(file, 11, 7));
	actions.emplace(IDLE_BACK,    new Animation(file, 11, 7));
	actions[IDLE_FORWARD]->SetIndex({ 0 }, false);
	actions[IDLE_SIDE]->SetIndex({ 2 },    false);
	actions[IDLE_BACK]->SetIndex({ 1 },    false);
	actions.emplace(WALK_FORWARD, new Animation(file, 11, 7));
	actions.emplace(WALK_SIDE, new Animation(file, 11, 7));
	actions.emplace(WALK_BACK, new Animation(file, 11, 7));
	actions[WALK_FORWARD]->SetPart(4, 8, true);
	actions[WALK_SIDE]->SetPart(4, 8, true);
	actions[WALK_BACK]->SetPart(12, 16, true);

	actions.emplace(ATTACK_FORWARD, new Animation(file, 11, 7));
	actions.emplace(ATTACK_SIDE, new Animation(file, 11, 7));
	actions.emplace(ATTACK_BACK, new Animation(file, 11, 7));
	actions[ATTACK_FORWARD]->SetPart(9, 10, false);
	actions[ATTACK_SIDE]->SetPart(9, 10,    false);
	actions[ATTACK_BACK]->SetPart(59, 60,   false);

	actions.emplace(CHARGE_FORWARD, new Animation(file, 11, 7));
	actions.emplace(CHARGE_SIDE, new Animation(file, 11, 7));
	actions.emplace(CHARGE_BACK, new Animation(file, 11, 7));
	actions[CHARGE_FORWARD]->SetPart(44, 49, false);
	actions[CHARGE_SIDE]->SetPart(44, 49,    false);
	actions[CHARGE_BACK]->SetPart(38, 43,    false);

	actions.emplace(SPIN_TO_FORWARD, new Animation(file, 11, 7));
	actions.emplace(SPIN_TO_BACK, new Animation(file, 11, 7));
	actions[SPIN_TO_FORWARD]->SetPart(22, 27, false);
	actions[SPIN_TO_BACK]->SetPart(33, 38,    false);
	
	actions.emplace(CHANGE_FORM, new Animation(file, 11, 7));
	actions[CHANGE_FORM]->SetPart(71, 66, false);

	


}

void Vatti::SetEndEvent()
{
	actions[ATTACK_FORWARD]->SetEndEvent(bind(&Vatti::SetIDLE, this));
	actions[ATTACK_SIDE]->SetEndEvent(bind(   &Vatti::SetIDLE, this));
	actions[ATTACK_BACK]->SetEndEvent(bind(   &Vatti::SetIDLE, this));
}


