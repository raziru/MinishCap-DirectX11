#pragma once
class Fire: public Effect
{
public:
	Fire();
	~Fire();


	void AddAction() override;

	virtual void Update();

	virtual void DisappearEvent() override;

	void CollisionLink();

	void Attack(Vector2 direct, Vector2 translation) override;

	void SetEndEvent();
	void Destory();

private:
	wstring file2;
	bool canMove = true;

};


