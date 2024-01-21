#pragma once
class SpinSword:public Weapon
{
public:
	SpinSword();
	~SpinSword();


	void AddAction() override;

	void Attack(Vector2 direct, Vector2 translation) override;
private:


	// Weapon을(를) 통해 상속됨

	// Character을(를) 통해 상속됨
};

