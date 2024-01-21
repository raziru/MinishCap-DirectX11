#pragma once
class Effect: public Weapon
{
public:
	Effect();
	~Effect();

	virtual void AddAction() = 0;

	virtual void Update();

	virtual void DisappearEvent() = 0;

protected:
	float duration = 0.0f;
	float deleteTime = 3.0f;
	Vector2 direct = {};
	float speed = 0;
};

