#include "Framework.h"
#include "ZeldaScene.h"

ZeldaScene::ZeldaScene()
{
	link = new Link;

	stages.push_back(new Stage1(link));
	stages.push_back(new Stage2(link));
	stages.push_back(new Stage3(link));
	stages.push_back(new Stage4(link));




	stage = stages[index];
	stage->SetStage(link);

	CAMERA->SetTarget(link);
}

ZeldaScene::~ZeldaScene()
{
	delete link;
	for (Stage* stage : stages)
	{
		delete stage;
	}
	stages.clear();
}

void ZeldaScene::Update()
{

	stage->Update();
	link->Update();
	if (stage->IsClear())
	{
		index++;
		stage = stages[index];
		stage->SetStage(link);
	}
	
	
}

void ZeldaScene::Render()
{
	stage->Render();
	link->Render();
}
