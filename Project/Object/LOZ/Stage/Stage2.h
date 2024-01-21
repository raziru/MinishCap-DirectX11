#pragma once
enum Phase
{
	PHASE1,
	PHASE2,
	PHASE3,
	PHASE4,

};
class Stage2:public Stage
{
public:
	Stage2(Link* link);
	~Stage2();
	void SetOnEvents() override;
	virtual void Update();
	virtual void Render();

	void SetStage(Link* link);

	void Phase1();
	void Phase2();
	void Phase3();

	void Phase4();

	bool AllKill();

private:
	UINT index = 0;
	Phase phase = PHASE1;
	bool phaseClear = false;
	Vatti* vatti = nullptr;
	float delay = 3.0f;
	float duration = 0.0f;
	bool turnOnPeaceful = false;


	//vector<MonsterManager*> monstersDirectory;
	// Stage을(를) 통해 상속됨

};



