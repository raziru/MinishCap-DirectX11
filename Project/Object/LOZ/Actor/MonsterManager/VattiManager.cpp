#include "Framework.h"
#include "VattiManager.h"

VattiManager::VattiManager()
{
	for (UINT i = 0; i < 1; i++)
	{
		monsters.push_back(new Vatti);
	}

	for (UINT i = 0; i < 4; i++)
	{
		monsters.push_back(new VattiTransform);
	}
}

VattiManager::~VattiManager()
{
}