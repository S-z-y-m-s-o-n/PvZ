
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PvZGameInstance.generated.h"

#define PlantC(name) UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class APlant> ##name

#define EnemyC(name) UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class AFightingActor> ##name

#define DEquipmentC(neme) UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class ADamagableEquipment> ##name

#define CLASS(name) Cast<UPvZGameInstance>(GetWorld()->GetGameInstance())->##name

#define PData Cast<UPvZGameInstance>(GetWorld()->GetGameInstance())->PlantData

UCLASS()
class UPlantData : public UObject
{
	GENERATED_BODY()

public:
	UPlantData() {};

	void SetValues(int sunCost, float cooldown, UTexture2D* texture);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SunCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Thumbnail;
};

UCLASS()
class PVZ_API UPvZGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class APlant> SunflowerClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class APlant> PeashooterClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class APlant> DoublePeashooterClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class APlant> WalnutClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class APlant> PoisonousBerryClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class APlant> TorchwoodClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class ADamagableEquipment> ConeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<class AFightingActor> StandardZombieClass;

	UPvZGameInstance();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<TSubclassOf<class APlant>, UPlantData*> PlantData;

	virtual void Init() override;
};
