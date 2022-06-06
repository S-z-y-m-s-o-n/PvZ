
#include "Plants/Plant.h"

#include "Materials/MaterialInstanceDynamic.h"

#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"

#include "Game/GridCell.h"

APlant::APlant()
{
	PrimaryActorTick.bCanEverTick = true;

	Side = ESide::Plants;

	SpriteComponent->TranslucencySortPriority = 1;

	BoxCollision->SetCollisionResponseToChannel(ECC_EngineTraceChannel2, ECollisionResponse::ECR_Overlap);

	bIsDamagable = false;
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

void APlant::Plant(AGridCell* gridCell)
{
	isPlanted = true;

	SpriteComponent->SetMaterial(0, NormalMaterial);

	SetActorLocation(gridCell->GetActorLocation() + FVector(0, 0.1, 0));
	SetActorRotation(FRotator(0,0,0));
	gridCell->bIsOccupied = true;
	gridCell->OccupyingPlant = this;
	OccupiedGridCell = gridCell;
	bIsDamagable = true;
}

void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APlant::CanBePlanted(AGridCell* gridCell)
{
	return !gridCell->bIsOccupied;
}