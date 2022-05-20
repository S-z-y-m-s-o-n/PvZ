
#pragma once

#include "CoreMinimal.h"
#include "Plant.h"
#include "Peashooter.generated.h"

UCLASS()
class PVZ_API APeashooter : public APlant
{
	GENERATED_BODY()

public:
	APeashooter();
	
protected:

	bool CanShoot = true;

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
};
