#pragma once
class BossRoom3:public BossRoom
{
public:
	BossRoom3();
	~BossRoom3();
	virtual void Update();
	virtual void Render();
private:


	// BossRoom��(��) ���� ��ӵ�
	void AddAction() override;

};


