#pragma once
class Stage4:public Stage
{
public:
	Stage4(Link* link);
	~Stage4();


	virtual void Update();
	virtual void Render();

	virtual void SetStage(Link* link);

	//virtual void SetStage() override;
private:


	// Stage��(��) ���� ��ӵ�
	void SetOnEvents() override;
	Zelda* zelda = nullptr;

};



