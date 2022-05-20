
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PvZGameInstance.generated.h"

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
	UPvZGameInstance();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<TSubclassOf<class APlant>, UPlantData*> PlantData;
};
