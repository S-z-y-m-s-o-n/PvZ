
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Game/PvZGameInstance.h"

#include "PvEBaseLevelGameMode.generated.h"

UCLASS()
class PVZ_API APvEBaseLevelGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	uint8 SelectedColumn = 0;
	uint8 SelectedRow = 0;

	void HighlightGrid();

	void ClearGridChoice();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class UMaterialInterface* GridMaterial1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class UMaterialInterface* GridMaterial2;

	UClass* ChoosenPlantClass;

	class APlant* ChoosenPlant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class AGridCell*> Grid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class AGridCell*> SpawningGrid;

	float ZombieSpawningTime = 10.5;

	class AGridCell* SelectedGridCell;

	void ChoosePlant(TSubclassOf<class APlant> PlantClass);

	FORCEINLINE void slot1() { ChoosePlant(CLASS(SunflowerClass)); }
	FORCEINLINE void slot2() { ChoosePlant(CLASS(PeashooterClass)); }
	FORCEINLINE void slot3() { ChoosePlant(CLASS(WalnutClass)); }
	FORCEINLINE void slot4() { ChoosePlant(CLASS(PoisonousBerryClass)); }
	FORCEINLINE void slot5() { ChoosePlant(CLASS(DoublePeashooterClass)); }

	void UnchoosePlant();
	void PlantOut();

	void LMB();

	void SpawnSun();

	void SpawnZombie();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class UUserWidget> SunCounterClass;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		int SunCount = 2;

	bool bSpawnSun = true;
	float SunSpawningSpeed = 8.f;

	friend class APlayerPawn;

	APvEBaseLevelGameMode();
};
