#pragma once
class BossRoom3:public BossRoom
{
public:
	BossRoom3();
	~BossRoom3();
	virtual void Update();
	virtual void Render();
private:


	// BossRoom을(를) 통해 상속됨
	void AddAction() override;

};


