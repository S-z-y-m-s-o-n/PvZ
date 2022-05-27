
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FightingActor.generated.h"

UENUM()
enum ESide
{
	Plants, 
	Zombies
};

UCLASS()
class PVZ_API AFightingActor : public AActor
{
	GENERATED_BODY()
public:	
	AFightingActor();

	ESide Side;

	uint8 Row;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UPaperFlipbookComponent* SpriteComponent;

	float health;

	bool bIsDamagable = true;
};
