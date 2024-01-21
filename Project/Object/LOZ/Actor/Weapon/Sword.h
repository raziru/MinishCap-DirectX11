#pragma once
class Sword:public Weapon
{
public:
	Sword();
	~Sword();

	
	void AddAction() override;
private:


	// Character을(를) 통해 상속됨

	

	// Weapon을(를) 통해 상속됨
	void Attack(Vector2 direct, Vector2 translation) override;

};



