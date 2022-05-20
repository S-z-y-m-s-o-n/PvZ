
#include "Game/PvZGameInstance.h"

#include "Plants/Plant.h"

#include "Plants/Sunflower.h"
#include "Plants/PeaShooter.h"
#include "Plants/Walnut.h"
#include "Plants/DoublePeashooter.h"
#include "Plants/PoisonousBerry.h"

UPvZGameInstance::UPvZGameInstance()
{
	UPlantData* SunflowerData = NewObject<UPlantData>();
	SunflowerData->SetValues(2, 1.f, NewObject<UTexture2D>());

	UPlantData* PeashooterData = NewObject<UPlantData>();
	PeashooterData->SetValues(4, 1.f, NewObject<UTexture2D>());

	UPlantData* WalnutData = NewObject<UPlantData>();
	WalnutData->SetValues(2, 1.f, NewObject<UTexture2D>());

	UPlantData* DoublePeashooterData = NewObject<UPlantData>();
	DoublePeashooterData->SetValues(8, 2.f, NewObject<UTexture2D>());

	UPlantData* PoisonousBerryData = NewObject<UPlantData>();
	PoisonousBerryData->SetValues(2, 0.8, NewObject<UTexture2D>());

	PlantData.Add(ASunflower::StaticClass(), SunflowerData);
	PlantData.Add(APeashooter::StaticClass(), PeashooterData);
	PlantData.Add(AWalnut::StaticClass(), WalnutData);
	PlantData.Add(ADoublePeashooter::StaticClass(), DoublePeashooterData);
	PlantData.Add(APoisonousBerry::StaticClass(), PoisonousBerryData);
}

void UPlantData::SetValues(int sunCost, float cooldown, UTexture2D* thumbnail)
{
	SunCost = sunCost;
	Cooldown = cooldown;
	Thumbnail = thumbnail;
}