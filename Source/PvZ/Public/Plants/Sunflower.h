
#pragma once

#include "CoreMinimal.h"
#include "Plant.h"
#include "Sunflower.generated.h"

UCLASS()
class PVZ_API ASunflower : public APlant
{
	GENERATED_BODY()

public:

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void SpawnSun();

	FTimerHandle Timer;
};
