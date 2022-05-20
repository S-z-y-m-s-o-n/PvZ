
#include "Plants/Plant.h"

#include "Materials/MaterialInstanceDynamic.h"

#include "Game/GridCell.h"

#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"

APlant::APlant()
{
	PrimaryActorTick.bCanEverTick = false;

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	SetRootComponent(Sprite);

	Sprite->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECollisionResponse::ECR_Block);
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

	Sprite->SetMaterial(0, NormalMaterial);

	SetActorLocation(GridCell->GetActorLocation() + FVector(0,0.01,0));
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