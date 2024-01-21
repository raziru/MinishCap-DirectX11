#pragma once
class Octa: public Monster
{
public:
	Octa();
	~Octa();


	virtual void Update();
	virtual void Render();

	void Attack();
	void SetIDLE();

	void SetEndEvent();

	

protected:
	float attackDelay = 5.0f;
	float time = 0.0f;
	// Monster을(를) 통해 상속됨

};

