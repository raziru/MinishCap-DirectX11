#pragma once

enum State
{
	IDLE,
	WALK,
	DAMAGED,
	PRAY,
	DEAD,
	REVIVE
};

enum AnimState
{
	IDLE_FORWARD,
	IDLE_SIDE,
	IDLE_BACK,
	WALK_FORWARD,
	WALK_SIDE,
	WALK_BACK,
	DAMAGED_FORWARD,
	DAMAGED_SIDE,
	DAMAGED_BACK,
	ANIM_PRAY,
	ANIM_DEAD,
	ANIM_ALREADYDEAD,
	ANIM_REVIVE
};
class Zelda:public Actor
{
	
	



public:
	Zelda();
	~Zelda();

	virtual void Update();
	virtual void Render();


	void SetState(State state) { this->state = state; }


	void Idle();

	void Walk();

	void Damaged();

	void Revive();


private:


	// Character을(를) 통해 상속됨
	void AddAction() override;

	bool canMove = false;
	Direct direct = FORWARD;

	Vector2 moveDirect = { 0,-1 };

	State state =IDLE;
	float speed = 30.0f;

};



