#pragma once
class TheEnd:public BackGround
{
public:
	TheEnd();
	~TheEnd();

	virtual void Update();
	virtual void Render();

	void AddAction() override;
private:

};



