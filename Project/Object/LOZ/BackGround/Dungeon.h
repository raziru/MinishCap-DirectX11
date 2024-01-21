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


	// BackGround을(를) 통해 상속됨

};

