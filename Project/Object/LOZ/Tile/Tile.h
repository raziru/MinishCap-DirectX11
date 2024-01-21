#pragma once
class Tile:public Actor
{
public:
	Tile();
	~Tile();

	virtual void AddAction() override;

	virtual void Update();
	virtual void Render();

	void SetOnEvent(function<void()> Event) { this->OnEvent = Event; }
	void SetOffEvent(function<void()> Event) { this->OffEvent = Event; }

	bool& OnCollision() { return onCollsion; }

	void TurnOnSound();
	void TurnOnOnce();

	
private:
	function<void()> OnEvent = nullptr;
	function<void()> OffEvent = nullptr;

	bool onCollsion = false;
	bool soundTurnOnOnce = false;
	// Character��(��) ���� ��ӵ�

};

