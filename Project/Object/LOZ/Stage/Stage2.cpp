#include "Framework.h"
#include "Stage2.h"

Stage2::Stage2(Link* link)
	:Stage(link)
{
	backgrounds.push_back(new BossRoom1);
	backgrounds.push_back(new BossRoom2);
	backgrounds.push_back(new BossRoom3);


	SetOnEvents();

	monsters = new VattiManager();

	//laser = new Laser;
	for (Monster* monster: monsters->GetBody())
	{
		monster->IsActive() = false;
	}
	SoundManager::GetInstance()->AddSound("Phase1", "_Sound/Vaati_sTheme.wav", true);
	SoundManager::GetInstance()->AddSound("Phase2",  "_Sound/VaatiReborn.wav", true);
	SoundManager::GetInstance()->AddSound("Phase3",   "_Sound/VaatiWrath.wav", true);
	SoundManager::GetInstance()->AddSound("Peaceful",   "_Sound/PeaceReturns.mp3", true);


}

Stage2::~Stage2()
{
	for (BackGround* background : backgrounds)
	{
		delete background;
	}
	backgrounds.clear();
	delete tiles;
	delete monsters;
	delete vatti;
}

void Stage2::SetOnEvents()
{
	tiles = new TileManager(1);
	for (Tile* tile: tiles->GetBody())
	{
		tile->SetParent(background);
	}
	tiles->GetBody()[0]->BodyCollider()->SetLabel("ClearTile");
	Events.push_back(bind(&Stage::ClearTile, this, tiles->GetBody()[0]));
	tilePositions.push_back(Vector2(0, 50));
	tiles->SetOnEvents(tilePositions, Events, 1);
	tiles->GetBody()[0]->IsActive() = false;

}

void Stage2::Update()
{
	if (phaseClear)
	{
		if (duration>=delay)
		{
			duration = 0;
			switch (phase)
			{
			case PHASE1:
				SoundManager::GetInstance()->Stop("Phase1");

				phase = PHASE2;
				Phase2();
				phaseClear = false;
				break;
			case PHASE2:
				SoundManager::GetInstance()->Stop("Phase2");

				phase = PHASE3;
				Phase3();
				phaseClear = false;
				break;
			case PHASE3:
				SoundManager::GetInstance()->Stop("Phase3");
				SoundManager::GetInstance()->Play("Secret");

				phase = PHASE4;
				Phase4();
				phaseClear = false;
				
				break;
			default:
				break;
			}


		}
		else
		{
			duration += Time::Delta();
		}
		
	}
	else
	{
		switch (phase)
		{
		case PHASE1:
			if (AllKill())
			{
				SoundManager::GetInstance()->Stop("FireShoot");
				SoundManager::GetInstance()->Stop("FireBurn");
				phaseClear = true;
			}
			break;
		case PHASE2:
			if (AllKill())
			{

				phaseClear = true;
			}
			break;
		case PHASE3:
			if (AllKill())
			{

				phaseClear = true;
			}
		case PHASE4:
			if (turnOnPeaceful== false)
			{

			}
			break;
		default:
			break;
		}
	}
	tiles->Update();
	Stage::Update();
}

void Stage2::Render()
{

	tiles->Render();
	Stage::Render();
	
}

void Stage2::SetStage(Link* link)
{
	Phase1();

	SoundManager::GetInstance()->Stop("HyruleSecret");

	Stage::SetStage(link);
	link->SetParent(background);
	link->OldPosition() = { 0,-50 };
	link->translation = { 0,-50 };
}

void Stage2::Phase1()
{
	SoundManager::GetInstance()->Play("Phase1");

	background = backgrounds[0];
	monsters->SetParent(background);
	monsters->GetBody()[0]->IsActive() = true;
	monsters->GetBody()[0]->translation = { 0,0 };
}

void Stage2::Phase2()
{
	
	SoundManager::GetInstance()->Play("Phase2");

	background = backgrounds[1];
	monsters->SetParent(background);
	monsters->GetBody()[1]->IsActive() = true;
	monsters->GetBody()[1]->translation = { 0,0 };
}

void Stage2::Phase3()
{

	SoundManager::GetInstance()->Play("Phase3");

	background = backgrounds[2];
	monsters->SetParent(background);
	monsters->GetBody()[2]->IsActive() = true;
	monsters->GetBody()[3]->IsActive() = true;
	monsters->GetBody()[4]->IsActive() = true;

	monsters->GetBody()[2]->translation = {-50,-50};
	monsters->GetBody()[3]->translation = {0,50};
	monsters->GetBody()[4]->translation = {50,-50};
}

void Stage2::Phase4()
{
	tiles->GetBody()[0]->SetParent(background);

	tiles->GetBody()[0]->IsActive() = true;
	tiles->GetBody()[0]->SetAction(2);

	SoundManager::GetInstance()->Play("Peaceful");
	
}

bool Stage2::AllKill()
{
	for (Monster* monster : monsters->GetBody())
	{
		if (monster->IsActive())
		{
			return false;
		}
	}
	return true;
}
