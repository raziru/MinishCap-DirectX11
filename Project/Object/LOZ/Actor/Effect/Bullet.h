#pragma once
class Bullet:public Effect
{
public:
	Bullet();
	~Bullet();

	virtual void Update();

	void AddAction() override;
	void DisappearEvent() override;
	void Attack(Vector2 direct, Vector2 Globalposition) override;

private:
	// Effect을(를) 통해 상속됨


	// Effect을(를) 통해 상속됨

};

