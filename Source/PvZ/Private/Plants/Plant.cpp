
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

	SetActorLocation(GridCell->GetActorLocation() + FVector(0, 0.1, 0));
	SetActorRotation(FRotator(0,0,0));
	GridCell->bIsOccupied = true;
	GridCell->OccupyingPlant = this;
	OccupiedGridCell = GridCell;
}

void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}