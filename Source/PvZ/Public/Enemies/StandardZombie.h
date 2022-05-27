
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

public:
	AStandardZombie();
};
