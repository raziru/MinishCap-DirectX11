#pragma once
class Sword:public Weapon
{
public:
	Sword();
	~Sword();

	
	void AddAction() override;
private:


	// Character��(��) ���� ��ӵ�

	

	// Weapon��(��) ���� ��ӵ�
	void Attack(Vector2 direct, Vector2 translation) override;

};



