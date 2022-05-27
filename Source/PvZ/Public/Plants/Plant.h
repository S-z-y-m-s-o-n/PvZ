
#pragma once

#include "Player/PlayerPawn.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Game/FightingActor.h"
#include "Plant.generated.h"

UCLASS()
class PVZ_API APlant : public AFightingActor
{
	GENERATED_BODY()

public:
	APlant();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterial* NormalMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterial* TranslucentMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxHealth;

	float Health;

	bool bIsDestructible = true;

	UPROPERTY()
	bool isPlanted = false;

	class AGridCell* OccupiedGridCell = nullptr;

	virtual void Plant(class AGridCell* GridCell);

	virtual void Damage(float value);

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};