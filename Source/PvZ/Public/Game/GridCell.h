
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridCell.generated.h"

UCLASS()
class PVZ_API AGridCell : public AActor
{
	GENERATED_BODY()

public:
	AGridCell();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		FVector2D GridPosition;

	bool bIsOccupied = false;

	class APlant* OccupyingPlant = nullptr;

	bool bIsSelected = false;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};