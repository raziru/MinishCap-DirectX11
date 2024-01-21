#include "Framework.h"
#include "Stage3.h"

Stage3::Stage3(Link* link)
	:Stage(link)
{
	zelda = new Zelda;
	background = new Cythal;

	monsters = new OctaManager(1,1,1);
	for (Monster* monster : monsters->GetBody())
	{
		monster->IsActive() = false;
	}

	SoundManager::GetInstance()->AddSound("Fountain", "_Sound/FairyFountain.wav", true);

	SetOnEvents();
}

Stage3::~Stage3()
{
	delete zelda;
	delete background;
	delete tiles;
	delete monsters;
	delete endingTile;
}

void Stage3::SetOnEvents()
{
	tiles = new TileManager(2);
	endingTile = new TileManager(1);


	for (Tile* tile : tiles->GetBody())
	{
		tile->SetParent(background);
	}

	for (Tile* tile : endingTile->GetBody())
	{
		tile->SetParent(background);
	}

	tiles->GetBody()[0]->BodyCollider()->SetLabel("ChangeCamera");
	tiles->GetBody()[1]->BodyCollider()->SetLabel("ClearTile");
	Events.push_back(bind(&Stage3::ChangeCamera, this, tiles->GetBody()[0]));
	Events.push_back(bind(&Stage::ClearTile, this, tiles->GetBody()[1]));
	
	tilePositions.push_back(Vector2(0, -48));
	tilePositions.push_back(Vector2(0, -20));

	tiles->SetOnEvents(tilePositions, Events, 2);

	tiles->GetBody()[1]->IsActive() = false;


	endingTile->GetBody()[0]->BodyCollider()->SetLabel("StopZelda");
	endingEvents.push_back(bind(&Stage3::StopZelda, this, endingTile->GetBody()[0]));
	endingtilePositions.push_back(Vector2(0,-30));
	endingTile->SetOnEvents(endingtilePositions, endingEvents, 1);
	endingTile->GetBody()[0]->BodyCollider()->SetColor(1,0,0);




}

void Stage3::Update()
{
	
	zelda->Update();
	endingTile->Update();
	Stage::Update();

	if (zelda->BodyCollider()->Collision(endingTile->GetBody()[0]->BodyCollider()))
	{
		endingTile->GetBody()[0]->OnCollision() = true;
	}
	else
	{
		endingTile->GetBody()[0]->OnCollision() = false;

	}
}

void Stage3::Render()
{
	Stage::Render();
	endingTile->Render();
	zelda->Render();

}

void Stage3::SetStage(Link* link)
{
	Stage::SetStage(link);

	SoundManager::GetInstance()->Stop("Peaceful");
	SoundManager::GetInstance()->Play("Fountain");




	zelda->SetParent(background);
	zelda->translation = { 0,70 };
	zelda->SetAction(ANIM_ALREADYDEAD);

	link->SetParent(background);
	link->OldPosition() = { 0,-90 };
	link->translation   = { 0,-90 };
}

void Stage3::StopZelda(Tile* tile)
{
	tile->IsActive() = false;
	zelda->SetAction(ANIM_PRAY);
	zelda->SetState(IDLE);
	CAMERA->SetTarget(link);
	link->CanControl() = true;
	tiles->GetBody()[1]->IsActive() = true;


}

void Stage3::ChangeCamera(Tile* tile)
{
	tile->IsActive() = false;
	CAMERA->SetTarget(zelda);
	zelda->Revive();
	link->CanControl() = false;

}

void Stage3::CollisionZelda()
{
	if (!zelda->BodyCollider()->IsActive())
	{
		return;
	}
	for (Tile* tile : endingTile->GetBody())
	{
		if (!tile->IsActive())
		{
			continue;
		}

		if (zelda->BodyCollider()->Collision(tile->BodyCollider()))
		{
			tile->OnCollision() = true;
		}
		else
		{
			tile->OnCollision() = false;

		}
	}
	for (Tile* tile : tiles->GetBody())
	{
		if (!tile->IsActive())
		{
			continue;
		}

		if (zelda->BodyCollider()->Collision(tile->BodyCollider()))
		{
			tile->OnCollision() = false;
		}
		else
		{
			tile->OnCollision() = false;

		}
	}
}

