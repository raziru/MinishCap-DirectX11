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
	// Effect��(��) ���� ��ӵ�


	// Effect��(��) ���� ��ӵ�

};

