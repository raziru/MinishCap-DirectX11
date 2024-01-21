#pragma once
class VattiTransform: public Monster
{
public:
	VattiTransform();
	~VattiTransform();

	virtual void Update() override;
	virtual void Render() override;

	void Attack();

private:
	float time = 0.0f;
	float attackDelay = 4.0f;

	// Monster을(를) 통해 상속됨
	void AddAction() override;

};


