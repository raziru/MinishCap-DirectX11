#pragma once
class Weapon: public Actor
{
public:
	Weapon();
	~Weapon();

	virtual void AddAction() = 0;

	virtual void Update();
	virtual void Render();

	virtual void Attack(Vector2 direct, Vector2 Globalposition) = 0;

	int Power() { return power; }

	void SetOnEvent(function<void()> Event) { this->OnEvent = Event; }
	void SetOffEvent(function<void()> Event) { this->OffEvent = Event; }

	bool& OnCollision() { return onCollsion; }
protected:
	int power = 0;

	function<void()> OnEvent = nullptr;
	function<void()> OffEvent = nullptr;

	bool onCollsion = false;

	// Character을(를) 통해 상속됨

};

