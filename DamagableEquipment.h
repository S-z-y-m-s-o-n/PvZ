
#pragma once

#include "CoreMinimal.h"

#include "Enemies/Equipment/Equipment.h"
#include "Game/Damage.h"

#include "DamagableEquipment.generated.h"

UCLASS()
class PVZ_API ADamagableEquipment : public AEquipment
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxHealth;

	float Health;

	virtual float Damage(float value, EDamageType damageType, AActor* source);

protected:

	virtual void BeginPlay() override;
};