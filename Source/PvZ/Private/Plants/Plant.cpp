
#include "Plants/Plant.h"

#include "Materials/MaterialInstanceDynamic.h"

#include "PaperFlipbookComponent.h"

#include "Game/GridCell.h"

APlant::APlant()
{
	PrimaryActorTick.bCanEverTick = true;

	Side = ESide::Plants;

	SpriteComponent->TranslucencySortPriority = 1;
}

void APlant::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
}

void APlant::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (EndPlayReason == EEndPlayReason::Destroyed)
	{
		if (OccupiedGridCell)
		{
			OccupiedGridCell->OccupyingPlant = nullptr;
			OccupiedGridCell->bIsOccupied = false;
		}
	}
}

void APlant::Plant(AGridCell* GridCell)
{
	isPlanted = true;

	SpriteComponent->SetMaterial(0, NormalMaterial);

	SetActorLocation(GridCell->GetActorLocation());
	SetActorRotation(FRotator(0,0,0));
	GridCell->bIsOccupied = true;
	GridCell->OccupyingPlant = this;
	OccupiedGridCell = GridCell;
}

void APlant::Damage(float value)
{
	Health -= value;
	if (Health <= 0)
	{
		Destroy();
	}
}

void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}