#pragma once
class SpinSword:public Weapon
{
public:
	SpinSword();
	~SpinSword();


	void AddAction() override;

	void Attack(Vector2 direct, Vector2 translation) override;
private:


	// Weapon��(��) ���� ��ӵ�

	// Character��(��) ���� ��ӵ�
};

