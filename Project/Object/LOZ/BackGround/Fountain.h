#pragma once
class Fountain:public BackGround
{
public:
	Fountain();
	~Fountain();

	virtual void Update() override;
	virtual void Render() override;
	void AddAction() override;
private:


	// BackGround��(��) ���� ��ӵ�

};


