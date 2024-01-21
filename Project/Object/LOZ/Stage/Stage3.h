#pragma once
class Stage3:public Stage
{
public:
	Stage3(Link* link);
	~Stage3();

	void SetOnEvents() override;
	virtual void Update();
	virtual void Render();

	void SetStage(Link* link);

	void StopZelda(Tile* tile);
	void ChangeCamera(Tile* tile);

	void CollisionZelda();


private:
	Zelda* zelda = nullptr;

	TileManager* endingTile = nullptr;
	vector <function<void()>> endingEvents;
	vector<Vector2>           endingtilePositions;
};

