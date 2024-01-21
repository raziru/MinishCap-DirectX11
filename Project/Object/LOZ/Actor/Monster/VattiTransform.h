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

	// Monster��(��) ���� ��ӵ�
	void AddAction() override;

};


