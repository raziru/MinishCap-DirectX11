#pragma once
enum EffectType
{
	BULLET,
	FIRE,
	LASER
};
class EffectManager
{
public:
	EffectManager(EffectType effect, Transform* parent, Vector2 translation);
	~EffectManager();

	void Update();
	void Render();

	void Initialize(Vector2 translation);

	void Attack(Vector2 direct,Vector2 translation);

	//Vector2& SetTranslation() { return translation; }
	
	void SetRotation(float rotate);


	bool IsEmpty();

	vector<Effect*> GetBody() { return effects; }

private:
	vector<Effect*> effects;
	Vector2 translation = {};

};


