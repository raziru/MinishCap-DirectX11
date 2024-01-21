#pragma once
class Laser:public Effect
{
public:
	Laser();
	~Laser();

	void AddAction() override;

	void DisappearEvent() override;

	void Attack(Vector2 direct,Vector2 translation) override;
	void SetEndEvent();

	void Beam();
	void Destroy();

	virtual void Update();

private:
	wstring file2;
	wstring file3;


	// Effect을(를) 통해 상속됨


	// Effect을(를) 통해 상속됨
	
};

