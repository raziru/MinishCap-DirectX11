#pragma once
class BossRoom2:public BossRoom
{
public:
	BossRoom2();
	~BossRoom2();

	virtual void Update();
	virtual void Render();

	void AddAction() override;
private:



};



