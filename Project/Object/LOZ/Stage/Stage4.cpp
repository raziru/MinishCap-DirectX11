#include "Framework.h"
#include "Stage4.h"

Stage4::Stage4(Link* link)
	:Stage(link)
{
	background = new TheEnd;
	zelda = new Zelda;
	SoundManager::GetInstance()->AddSound("HyruleField", "_Sound/HyruleField.wav", true);

}

Stage4::~Stage4()
{
	delete zelda;
	delete background;
}

void Stage4::Update()
{

	link->scale = { 3,3 };
	zelda->scale = { 3,3 };

	link->CanControl()= false;
	link->translation = { -30,-90 };
	zelda->translation = link->translation + Vector2(60,5);
	zelda->Update();
	background->Update();
	//Stage::Update();
}

void Stage4::Render()
{

	background->Render();
	zelda->Render();
	//Stage::Render();

}

void Stage4::SetStage(Link* link)
{
	Stage::SetStage(link);
	link->SetEnding();
	CAMERA->SetTarget(background);

	zelda->SetParent(background);
	zelda->SetAction(IDLE_FORWARD);

	SoundManager::GetInstance()->Stop("Fountain");
	SoundManager::GetInstance()->Play("HyruleField");

}

void Stage4::SetOnEvents()
{
}
