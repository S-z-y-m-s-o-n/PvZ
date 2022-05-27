

#include "Game/PvEBaseLevelGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "PaperSpriteComponent.h"
#include "PaperFlipbookComponent.h"

#include "Game/GridCell.h"
#include "Game/PvZGameInstance.h"

#include "Player/PlayerPawn.h"
#include "Plants/Plant.h"

#include "Enemies/StandardZombie.h"

#include <ctime>

APvEBaseLevelGameMode::APvEBaseLevelGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APvEBaseLevelGameMode::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetGameInstance(), SunCounterClass);
	Widget->AddToViewport();

	if (bSpawnSun)
	{
		FTimerHandle Handle;
		GetWorldTimerManager().SetTimer(Handle, this, &APvEBaseLevelGameMode::SpawnSun, SunSpawningSpeed, true);
	}

	TArray<AActor*> GridActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGridCell::StaticClass(), GridActors);
	for (uint8 i = 0; i < GridActors.Num(); i++)
	{
		Grid.Add(Cast<AGridCell>(GridActors[i]));
	}

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	for (int i = 0; i < Grid.Num(); i++)
	{
		if (Grid[i]->GridPosition.Y == 9)
		{
			SpawningGrid.Add(Grid[i]);
		}
	}

	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, this, &APvEBaseLevelGameMode::SpawnZombie, ZombieSpawningTime, false);
}

void APvEBaseLevelGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ChoosenPlant && !ChoosenPlant->isPlanted)
	{
		FHitResult Hit;
		if (GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECC_GameTraceChannel1, true, Hit))
		{
			ChoosenPlant->SpriteComponent->SetVisibility(true);
			ChoosenPlant->SetActorLocation(Hit.ImpactPoint + FVector(0, 0.1, 0));
		}
		else
		{
			ChoosenPlant->SpriteComponent->SetVisibility(false);
		}
	}
	ClearGridChoice();
	if (ChoosenPlant)
	{
		FHitResult Hit;
		GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECC_GameTraceChannel1, true, Hit);
		if (AGridCell* GridCell = Cast<AGridCell>(Hit.Actor))
		{
			if (!GridCell->bIsOccupied)
			{
				SelectedRow = GridCell->GridPosition.X;
				SelectedColumn = GridCell->GridPosition.Y;
				HighlightGrid();
			}
		}
	}
}

void APvEBaseLevelGameMode::ChoosePlant(TSubclassOf<APlant> PlantClass)
{
	UnchoosePlant();

	ChoosenPlantClass = PlantClass;
	ChoosenPlant = GetWorld()->SpawnActor<APlant>(PlantClass.Get(), FVector(), FRotator());
}

void APvEBaseLevelGameMode::UnchoosePlant()
{
	if (ChoosenPlant != nullptr && ChoosenPlantClass != nullptr)
	{
		ChoosenPlant->Destroy();
		ChoosenPlant = nullptr;
		ChoosenPlantClass = nullptr;
	}
}

void APvEBaseLevelGameMode::PlantOut()
{
	FHitResult Hit;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
	if (Hit.Actor->IsA<AGridCell>())
	{
		AGridCell* GridCell = Cast<AGridCell>(Hit.Actor);
		if (GridCell->OccupyingPlant != nullptr)
		{
			GridCell->OccupyingPlant->Destroy();
		}
	}
}

void APvEBaseLevelGameMode::ClearGridChoice()
{
	SelectedColumn = 0;
	SelectedRow = 0;
	SelectedGridCell = nullptr;
	HighlightGrid();
}

void APvEBaseLevelGameMode::LMB()
{
	if (ChoosenPlantClass != nullptr && Cast<UPvZGameInstance>(GetGameInstance())->PlantData.Find(ChoosenPlantClass->GetSuperClass()))
	{
		UPlantData* ChoosenPlantData = *Cast<UPvZGameInstance>(GetGameInstance())->PlantData.Find(ChoosenPlantClass->GetSuperClass());
		if (SelectedColumn != 0 && SelectedRow != 0 && !SelectedGridCell->bIsOccupied
			&& ChoosenPlantData->SunCost <= SunCount)
		{
			ChoosenPlant->Plant(SelectedGridCell);
			SunCount -= ChoosenPlantData->SunCost;

			ClearGridChoice();
			ChoosenPlant = nullptr;
			ChoosenPlantClass = nullptr;
		}
	}
}

void APvEBaseLevelGameMode::HighlightGrid()
{
	if (SelectedColumn != 0 && SelectedRow != 0)
	{
		for (uint8 i = 0; i < Grid.Num(); i++)
		{
			if (Grid[i]->GridPosition.Y == SelectedColumn)
			{
				Grid[i]->Sprite->SetMaterial(0, GridMaterial1);
				Grid[i]->Sprite->SetVisibility(true);
			}
			if (Grid[i]->GridPosition.X == SelectedRow)
			{
				Grid[i]->Sprite->SetMaterial(0, GridMaterial1);
				Grid[i]->Sprite->SetVisibility(true);
			}
			if (Grid[i]->GridPosition.X == SelectedRow && Grid[i]->GridPosition.Y == SelectedColumn)
			{
				Grid[i]->Sprite->SetMaterial(0, GridMaterial2);
				Grid[i]->Sprite->SetVisibility(true);
				SelectedGridCell = Grid[i];
			}
		}
	}
	else
	{
		for (uint8 i = 0; i < Grid.Num(); i++)
		{
			Grid[i]->Sprite->SetVisibility(false);
		}
	}
}

void APvEBaseLevelGameMode::SpawnSun()
{
	SunCount += 2;
}

void APvEBaseLevelGameMode::SpawnZombie()
{
	int row = FMath::RandRange(0, SpawningGrid.Num()-1);
	AStandardZombie* zombie = Cast<AStandardZombie>(GetWorld()->SpawnActor(StandardZombieClass.Get()));
	zombie->SetActorLocation(SpawningGrid[row]->GetActorLocation());
	zombie->Row = row + 1;

	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, this, &APvEBaseLevelGameMode::SpawnZombie, ZombieSpawningTime = (ZombieSpawningTime * (0.98 - ZombieSpawningTime / 130)), false);
}
