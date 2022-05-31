
#pragma once

#include "CoreMinimal.h"
#include "Game/FightingActor.h"
#include "StandardZombie.generated.h"

UCLASS()
class PVZ_API AStandardZombie : public AFightingActor
{
	GENERATED_BODY()

protected:

	virtual void Tick(float DeltaTime) override;

	float speed = 17.5;

	UPROPERTY()
		class ADamagableEquipment* Armor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<AActor*> overlappingActors;

public:

	virtual void SetArmor(class ADamagableEquipment* armor);

	virtual float Damage(float value, enum EDamageType damageType, AActor* source) override;

	virtual void EndPlay(EEndPlayReason::Type reason) override;

	AStandardZombie();
};
