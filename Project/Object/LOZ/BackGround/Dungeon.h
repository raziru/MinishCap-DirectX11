#pragma once
class Dungeon:public BackGround
{
public:
	Dungeon();
	~Dungeon();

	virtual void Update() override;
	virtual void Render() override;
	void AddAction() override;

private:


	// BackGround��(��) ���� ��ӵ�

};

