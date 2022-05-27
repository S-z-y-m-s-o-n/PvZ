
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

	virtual void Plant(class AGridCell* cell) override;
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class APeaProjectile> ProjectileClass;

	bool bCanShoot = true;

	FORCEINLINE void PrepareShoot() { bReadyToShoot = true; }

	bool bReadyToShoot = false;

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
};
