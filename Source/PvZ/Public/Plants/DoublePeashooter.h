
#pragma once

#include "CoreMinimal.h"
#include "Plant.h"
#include "DoublePeashooter.generated.h"

UCLASS()
class PVZ_API ADoublePeashooter : public APlant
{
	GENERATED_BODY()


public:
	virtual void Plant(class AGridCell* cell) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class APeaProjectile> ProjectileClass;

	FORCEINLINE void PrepareShoot() { bReadyToShoot = true; }

	void Shoot(bool bContinue);

	FORCEINLINE void ShootT() { Shoot(true); }
	FORCEINLINE void ShootF() { Shoot(false); }

	bool bReadyToShoot = false;

	virtual void Tick(float DeltaTime) override;
};
